//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "inet/common/ModuleAccess.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/packet/Packet.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "inet/applications/base/ApplicationPacket_m.h"
#include "../../applications/mamapp/BMeshPacket_m.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <ctime>
#include "QuadrantDroneProtocol.h"

namespace gradys_simulations {
Define_Module(QuadrantDroneProtocol);

void QuadrantDroneProtocol::initialize(int stage) {

    CommunicationProtocolBase::initialize(stage);
    droneUuid = this->getParentModule()->par("mobileNodeUUid").str();
    trackUuid = this->par("trackUuid").str();

    if (stage == INITSTAGE_LOCAL) {
        timeoutDuration = par("timeoutDuration");

        int duration = timeoutDuration.inUnit(SimTimeUnit::SIMTIME_S);
        // Signal that carries current data load and is emitted every time it is updated
        dataLoadSignalID = registerSignal("dataLoad");
        dronesSignalID = registerSignal("dronesIDsList");
        oxSignalID = registerSignal("oxenIDsList");
        emit(dataLoadSignalID, currentDataLoad);
        emit(dronesSignalID, this->getdronesIDsList().c_str());
        emit(oxSignalID, this->oxenIDsList.c_str());

        updatePayload();

        WATCH(leftNeighbours);
        WATCH(rightNeighbours);
        WATCH(communicationStatus);
        WATCH(tentativeTarget);
        WATCH(lastTarget);
        WATCH(currentDataLoad);
        WATCH(dronesIDsList);
        WATCH(oxenIDsList);
    }
}

void QuadrantDroneProtocol::handleTelemetry(gradys_simulations::Telemetry *telemetry) {
    if (currentTelemetry.getCurrentCommand() != -1
            && telemetry->getCurrentCommand() == -1) {
        resetParameters();
        initiateTimeout(timeoutDuration);
    }

//     Records if the drone has reached an edge and erases the neighbours after that edge
    if (currentTelemetry.getDroneActivity() != REACHED_EDGE
            && telemetry->getDroneActivity() == REACHED_EDGE) {
        if (telemetry->isReversed()) {
            rightNeighbours = 0;
        } else {
            leftNeighbours = 0;
        }
    }

// Erases neighbours when drone is recharging or shutdown
    if ((currentTelemetry.getDroneActivity() != RECHARGING
            && telemetry->getDroneActivity() == RECHARGING)
            || (currentTelemetry.getDroneActivity() != SHUTDOWN
                    && telemetry->getDroneActivity() == SHUTDOWN)) {
        leftNeighbours = rightNeighbours = 0;
    }

    currentTelemetry = *telemetry;

    if (telemetry->hasObject("tourCoords")) {
        tour =
                *(std::vector<Coord>*) telemetry->par("tourCoords").pointerValue();
    }

    // Telemetry during timeout is not stable, it may contain information that
    // has changed after message exchange started
    if (!isTimedout()) {
        lastStableTelemetry = *telemetry;
    }
    updatePayload();
}

void QuadrantDroneProtocol::handlePacket(Packet *pk) {
//    this->checkMobility();
    // Loads the QuadrantMessage from the recieved packet
    auto payload = dynamicPtrCast<const QuadrantMessage>(pk->peekAtBack());

    if (payload != nullptr) {
        bool destinationIsGroundstation = payload->getNextWaypointID() == -1;

//        std::cout << "UUIDS:" << payload->getUuids() << endl;

        switch (payload->getSenderType()) {
        case SENSOR:
//            std::cout << "mensagem de SENSOR:" << payload->getSourceID()
//                    << endl;

            this->insertFoundOx(payload->getUuids());
//            this->insertFoundOx(pk->getSenderModule()->par("sensorUid").str());
            break;
        case DRONE:
//            std::cout << "mensagem de DRONE:" << payload->getSourceID() << "com UUIDs:" << payload->getUuids() << endl;
            this->insertFoundDrone(
                    std::to_string(this->getParentModule()->getId()));
            this->refreshdronesIDs(payload->getDrones());
            this->refreshOxIDs(payload->getUuids());
            break;
        case GROUND_STATION:
//            std::cout << "mensagem de GROUND STATION:" << payload->getSourceID()
//                    << endl;
            this->refreshOxIDs(payload->getUuids());
            this->insertFoundDrone(
                    std::to_string(this->getParentModule()->getId()));
            this->refreshdronesIDs(payload->getDrones());
            if (this->getParentModule()->getId() == 10) {
//                sendFinish(payload->getUuids());
            }
            break;
        default:
            break;

        }

//        if (this->getParentModule()->getId() == 10) {
//        if (this->getParentModule()->getId() == 7) {
            auto end = std::chrono::system_clock::now();
            std::time_t end_time = std::chrono::system_clock::to_time_t(end);
            std::cout << "[ATUAL: "<< std::ctime(&end_time) <<"] \n\tDRONES::" << this->getdronesIDsList()<< endl;
            std::cout << "\tOXEN #" << this->getOxIDs().size() << "::"
                    << this->getOxIDsList() << endl;
            std::cout
                    << "----------------------------------------------------\n\n"
                    << endl;

            if (this->getOxIDs().size()>2 && this->getOxIDs().size() == (int)this->getParentModule()->getParentModule()->par("numSensors")){
                std::cout << "total: " << (int)this->getParentModule()->getParentModule()->par("numSensors") <<endl;
//                this->sendFinish(this->getOxIDs()[this->getOxIDs().size() - 1]);
            }
//        }
        auto mamPayload = dynamicPtrCast<const BMeshPacket>(pk->peekAtBack());
        if (mamPayload != nullptr) {
            if (!isTimedout() && communicationStatus == FREE) {
                currentDataLoad++;
                stableDataLoad = currentDataLoad;
                emit(dataLoadSignalID, currentDataLoad);
                emit(dronesSignalID, this->getdronesIDsList().c_str());
                emit(oxSignalID, this->getOxIDsList().c_str());
            }
        }
    } else {
        std::cout << "payload null" << endl;
    }
}

void QuadrantDroneProtocol::checkMobility(){
    bool tracking = this->isTracking();

    if(tracking){
        MobilityCommand *command = new MobilityCommand();
            command->setCommandType(MobilityCommandType::GOTO_WAYPOINT);
            sendCommand(command);

    }else{
        MobilityCommand *command = new MobilityCommand();
                    command->setCommandType(MobilityCommandType::RETURN_TO_HOME);
                    sendCommand(command);

                    MobilityCommand *command2 = new MobilityCommand();
                                command2->setCommandType(MobilityCommandType::IDLE_TIME);
                                sendCommand(command2);

    }
}

void QuadrantDroneProtocol::updatePayload() {
    // Creates message template with current content and correct type
    QuadrantMessage *payload = new QuadrantMessage();
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    payload->setSenderType(DRONE);

    // Sets the reverse flag on the payload
    payload->setReversed(lastStableTelemetry.isReversed());
    payload->setNextWaypointID(lastStableTelemetry.getNextWaypointID());
    payload->setLastWaypointID(lastStableTelemetry.getLastWaypointID());

    payload->setLeftNeighbours(leftNeighbours);
    payload->setRightNeighbours(rightNeighbours);

    payload->setSourceID(this->getParentModule()->getId());
    payload->setDrones(this->getdronesIDsList().c_str());
    payload->setUuids(this->getOxIDsList().c_str());

//    // Sends command to the communication module to start using this message
//    CommunicationCommand *command = new CommunicationCommand();
//    command->setCommandType(CommunicationCommandType::SET_PAYLOAD);
//    command->setPayloadTemplate(payload);
//    sendCommand(command);

    if (!isTimedout() && communicationStatus != FREE) {
        communicationStatus = FREE;
    }

    switch (communicationStatus) {
    case FREE:
        break;
    case REQUESTING: {
        payload->setDestinationID(tentativeTarget);
//        payload->setContent(content);
        break;
    }
    case PAIRED:
    case PAIRED_FINISHED: {
        payload->setDestinationID(tentativeTarget);
        payload->setDataLength(stableDataLoad);
        break;
    }
    case COLLECTING:
        break;
    }

    // Only send the update command if the payload has actually changed
    if (payload->getSourceID() != lastPayload.getSourceID()
            || payload->getDestinationID() != lastPayload.getDestinationID()
            || payload->getNextWaypointID() != lastPayload.getNextWaypointID()
            || payload->getLastWaypointID() != lastPayload.getLastWaypointID()
            || payload->getReversed() != lastPayload.getReversed()) {
        lastPayload = *payload;

        CommunicationCommand *command = new CommunicationCommand();
        command->setCommandType(SET_PAYLOAD);
        command->setPayloadTemplate(payload);
        sendCommand(command);
    } else {
        delete payload;
    }

}

void QuadrantDroneProtocol::setTarget(const char *target) {
    CommunicationCommand *command = new CommunicationCommand();
    command->setCommandType(SET_TARGET);
    command->setTarget(target);
    sendCommand(command);
}

void QuadrantDroneProtocol::finish() {
    CommunicationProtocolBase::finish();

//    for (auto const &item : contentSources) {
//        recordScalar(item.first.c_str(), item.second);
//    }
}

bool QuadrantDroneProtocol::isTimedout() {
    // Blocks the timeout if the drone is currently executing a command
    if (currentTelemetry.getCurrentCommand() != -1) {
        return true;
    }

    bool oldValue = timeoutSet;
    bool value = CommunicationProtocolBase::isTimedout();
    if (!value && oldValue) {
        resetParameters();
    }
    return value;
}

void QuadrantDroneProtocol::resetParameters() {
    timeoutSet = false;
    lastTarget = tentativeTarget;
    tentativeTarget = -1;
    tentativeTargetName = "";
    setTarget("");
    communicationStatus = FREE;

    lastStableTelemetry = currentTelemetry;
    stableDataLoad = currentDataLoad;
    updatePayload();
}

void QuadrantDroneProtocol::insertFoundDrone(std::string id) {
    //Checks if the current ID has already been inserted in the Drones Ids list
    bool exist = false;
    for (int i = 0; i < this->dronesIDs.size(); i++) {
        if (this->dronesIDs[i] == id) {
            exist = true;
            break;
        }
    }
    if (!exist && id != "1" && id != "-1") {
        this->dronesIDs.push_back(id);
    }

}

void QuadrantDroneProtocol::insertDronesIDs(std::vector<std::string> ids) {
    for (int i = 0; i < ids.size(); i++) {
        this->insertFoundDrone(ids[i]);
    }
}
std::vector<std::string> QuadrantDroneProtocol::getDronesIDs() {
    return this->dronesIDs;
}
std::string QuadrantDroneProtocol::getdronesIDsList() {

    std::string dronesList = "";
    for (int i = 0; i < this->dronesIDs.size(); i++) {
        if (i == 0) {
//            dronesList = std::to_string(this->dronesIDs[i]);
            dronesList = this->dronesIDs[i];
        } else {
//            dronesList = dronesList + ";" + std::to_string(this->dronesIDs[i]);
            dronesList = dronesList + ";" + this->dronesIDs[i];
        }

    }
    return dronesList;
}
void QuadrantDroneProtocol::refreshdronesIDs(std::string dronesList) {
    for (int i = 0; i < dronesList.length(); i++) {
        for (int j = i + 1; j < dronesList.length(); j++) {
            if (dronesList[j] == ';') {
//                std::cout << "Adicionando drone :: " << dronesList.substr(i, j - i)<< endl;
                this->insertFoundDrone(dronesList.substr(i, j - i));
                i = j;
                break;
            }
            if (j == (dronesList.length() - 1)) {
//                std::cout << "Adicionando drone :: " << dronesList.substr(i, (j - i)+1)<< endl;
                this->insertFoundDrone(dronesList.substr(i, (j - i) + 1));
                i = j;
                break;
            }

        }
    }
}

void QuadrantDroneProtocol::insertFoundOx(std::string id) {
    //Checks if the current ID has already been inserted in the Drones Ids list
    bool exist = false;
    for (int i = 0; i < this->oxIDs.size(); i++) {
        if (this->oxIDs[i] == id) {
            exist = true;
            break;
        }
    }
    if (!exist && id != "1" && id != "-1") {
        this->oxIDs.push_back(id);
//        sendFoundOx(id);
    }

}

void QuadrantDroneProtocol::insertOxIDs(std::vector<std::string> ids) {
    for (int i = 0; i < ids.size(); i++) {
        this->insertFoundOx(ids[i]);
    }
}
std::vector<std::string> QuadrantDroneProtocol::getOxIDs() {
    return this->oxIDs;
}
std::string QuadrantDroneProtocol::getOxIDsList() {

    std::string oxList = "";
    for (int i = 0; i < this->oxIDs.size(); i++) {
        if (i == 0) {
//            oxList = std::to_string(this->oxIDs[i]);
            oxList = this->oxIDs[i];
        } else {
//            oxList = oxList + ";" + std::to_string(this->oxIDs[i]);
            oxList = oxList + ";" + this->oxIDs[i];
        }

    }
    return oxList;
}
void QuadrantDroneProtocol::refreshOxIDs(std::string oxList) {
    for (int i = 0; i < oxList.length(); i++) {
        for (int j = i + 1; j < oxList.length(); j++) {
            if (oxList[j] == ';') {
//                std::cout << "Adicionando boi :: " << oxList.substr(i, j - i)<< endl;
                this->insertFoundOx(oxList.substr(i, j - i));
                i = j;
                break;
            }
            if (j == (oxList.length() - 1)) {
//                std::cout << "Adicionando boi :: " << oxList.substr(i, (j - i)+1)<< endl;
                this->insertFoundOx(oxList.substr(i, (j - i) + 1));
                i = j;
                break;
            }

        }
    }
}

void QuadrantDroneProtocol::sendFoundOx(std::string oxID) {

    //    std::string jarFilePath = "";
//    jarFilePath.assign("java -jar ");
//    jarFilePath.append(
//            "C:\\Users\\mille\\git\\repository2\\ICMU-T1-rastreamento-cliente\\target\\ICMU-T1-rastreamento-cliente-0.1-jar-with-dependencies.jar");
//    jarFilePath.append(" \"01111111-1111-1111-1111-111111166666\" ");
//    jarFilePath.append("false ");
//    jarFilePath.append(oxID);
//
//    printf("Jar execution path:  %s", jarFilePath.c_str());
//
//    system(jarFilePath.c_str());
//std::string grazeId = getTrackIdFile(); ;
//    std::string cmd = "java -jar ";
//    cmd = cmd + "C:\\Users\\mille\\git\\repository2\\ICMU-T1-rastreamento-cliente\\target\\ICMU-T2-DroneNode-0.9-jar-with-dependencies.jar";
//    cmd = cmd + " \"" +this->getDroneUuid() + "\" ";

//    cmd = cmd + " \"" + this->getParentModule()->par("mobileNodeUUid").str() + "\" ";
//    std::cout << "grazde ID: " << grazeId << endl;
//    cmd = cmd + " \"" +  this->getParentModule()->par("trackingUUid").str() + "\" ";
    //    cmd = cmd + " \"" +  this->trackUuid + "\" ";
//        cmd = cmd + " \"" +  grazeId + "\" ";


//    cmd = cmd + "false ";
//    cmd = cmd + oxID;
//    std::cout << cmd <<endl;
//
//    char buffer[128];
//    std::string result = "";
//    FILE *pipe = _popen(cmd.c_str(), "r");
//    if (!pipe)
//        throw std::runtime_error("popen() failed!");
////    try {
////        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
////            result += buffer;
////        }
////    } catch (...) {
////        _pclose(pipe);
////        throw;
////    }
//    _pclose(pipe);
}

void QuadrantDroneProtocol::sendFinish(std::string oxID) {
    std::string cmd = "java -jar ";
    cmd = cmd + "C:\\Users\\mille\\git\\repository2\\ICMU-T1-rastreamento-cliente\\target\\ICMU-T2-DroneNode-0.9-jar-with-dependencies.jar";
            this->getParentModule()->par("trackingUUid") = this->getTrackIdFile();
    cmd = cmd + " \"" + this->getParentModule()->par("mobileNodeUUid").str()  + "\" ";
//    std::cout << "grazde ID: " << grazeId << endl;
//    cmd = cmd + " \"" +  this->trackUuid + "\" ";
    cmd = cmd + " \"" +  this->getParentModule()->par("trackingUUid").str() + "\" ";
    cmd = cmd + "true ";
    cmd = cmd + oxID;
    std::cout << cmd <<endl;

//    char buffer[128];
//    std::string result = "";
//    FILE *pipe = _popen(cmd.c_str(), "r");
//    if (!pipe)
//        throw std::runtime_error("popen() failed!");
////    try {
////        while (fgets(buffer, sizeof buffer, pipe) != NULL) {
////            result += buffer;
////        }
////    } catch (...) {
////        _pclose(pipe);
////        throw;
////    }
//    _pclose(pipe);
}


std::string QuadrantDroneProtocol::getDroneUuid(){
    return this->droneUuid;

}

std::string QuadrantDroneProtocol::getTrackUuid(){
        return this->trackUuid;

}

void QuadrantDroneProtocol::setDroneUuid(std::string dUuid){
        this->droneUuid = dUuid;

}

void QuadrantDroneProtocol::setTrackUuid(std::string tUuid){
        this->trackUuid = tUuid;
}

bool QuadrantDroneProtocol::isTracking(){
    bool status = false;
    std::string grazeId = "";
        std::string track = "";
        std::ifstream myfile("../../../tmp_drones_uuid.txt");

        if (myfile.is_open()) {
            std::getline(myfile, grazeId);
            std::getline(myfile, track);
            myfile.close();
        }
        std::cout << grazeId << endl;
        if (track == "1"){
            //mobilidade dos drones = tracking
            status = true;
        }
        this->trackUuid = grazeId;
        this->getParentModule()->par("trackingUUid") = this->trackUuid;

    return status;
}

std::string QuadrantDroneProtocol::getTrackIdFile(){
    std::string grazeId = "";
            std::string track = "";
            std::ifstream myfile("../../../tmp_drones_uuid.txt");

            if (myfile.is_open()) {
                std::getline(myfile, grazeId);
                std::getline(myfile, track);
                myfile.close();
            }
            std::cout << grazeId << endl;
            return grazeId;
}


} /* namespace gradys_simulations */

