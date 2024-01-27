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

#include <string>

#include "inet/common/ModuleAccess.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/lifecycle/ModuleOperations.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "inet/applications/base/ApplicationPacket_m.h"
#include "HICAGroundProtocol.h"

namespace gradys_simulations {

Define_Module(HICAGroundProtocol);

void HICAGroundProtocol::initialize(int stage) {

    emit(registerSignal("dataLoad"), content);

    // Sets the correct payload
    HICAMessage *payload = new HICAMessage();
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    payload->setSenderType(GROUND_STATION);
    payload->setContent(0);

    CommunicationCommand *command = new CommunicationCommand();
    command->setCommandType(CommunicationCommandType::SET_PAYLOAD);
    command->setPayloadTemplate(payload);
    sendCommand(command);
}

void HICAGroundProtocol::handlePacket(Packet *pk) {
    auto message = pk->peekAtBack<HICAMessage>(B(7), 1);

    if (message != nullptr) {
        switch (message->getSenderType()) {
        case DRONE: {

            // Emits signal on data content change
//                emit(registerSignal("dataLoad"), current);

            this->setdronesIDs(message->getDrones());

            CommunicationCommand *targetCommand = new CommunicationCommand();
            targetCommand->setCommandType(CommunicationCommandType::SET_TARGET);
            targetCommand->setTarget(pk->getName());
            sendCommand(targetCommand);
            break;
        }
        case SENSOR: {
            break;
        }
        case GROUND_STATION: {
            break;
        }
        default: {
            MobilityCommand *initCommand = new MobilityCommand();
            initCommand->setCommandType(MobilityCommandType::GOTO_WAYPOINT);
            initCommand->setParam1(2);
            sendCommand(initCommand);
        }
        }
    }
}

void HICAGroundProtocol::setdronesIDs(std::string ids) {
    this->dronesIDs = ids;
}

std::string HICAGroundProtocol::getdronesIDs() {
    return this->dronesIDs;
}

std::string HICAGroundProtocol::getOxenIDs() {
    return this->oxenIDs;
}
void HICAGroundProtocol::setOxenIDs(std::string oxen) {
    this->oxenIDs = oxen;
}
std::string HICAGroundProtocol::getOxenCoords() {
    return this->oxenCoords;
}
void HICAGroundProtocol::setOxenCoords(std::string coords) {
    this->oxenCoords = coords;
}

void HICAGroundProtocol::setUuid(std::string gs_uuid){
    this->uuid = gs_uuid;
}

std::string HICAGroundProtocol::getUuid(){
    return this->uuid;
}

std::string HICAGroundProtocol::getTrackUuid(){
        return this->trackUuid;

}


void HICAGroundProtocol::setTrackUuid(std::string tUuid){
        this->trackUuid = tUuid;
}


/* namespace gradys_simulations */

}
