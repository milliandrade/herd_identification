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

#include "../messages/network/QuadrantMessage_m.h"
#include "inet/common/ModuleAccess.h"
#include "inet/common/TagBase_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/common/packet/Packet.h"
#include "QuadrantSensorProtocol.h"

namespace gradys_simulations {
Define_Module(QuadrantSensorProtocol);

void QuadrantSensorProtocol::initialize(int stage) {

    CommunicationProtocolBase::initialize(stage);
    // Loading payload size parameter
    payloadSize = par("payloadSize");
    uuid = this->getParentModule()->par("sensorUid").str();

// Sets the correct payload
    QuadrantMessage *payload = new QuadrantMessage();
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    payload->setSenderType(SENSOR);
    payload->setContent(payloadSize);
    payload->setUuids(uuid.c_str());

//    std::cout << "[SENSOR] [ID: " << this->getParentModule()->getId()
//            << "] inicializando .... [UUID: " << uuid.c_str() << "]." << endl;

    CommunicationCommand *command = new CommunicationCommand();
    command->setCommandType(CommunicationCommandType::SET_PAYLOAD);
    command->setPayloadTemplate(payload);
    sendCommand(command);
}

void QuadrantSensorProtocol::handlePacket(Packet *pk) {
    // Loading message from packet
    auto message = pk->peekAtFront<QuadrantMessage>(B(7), 1);
    uuid = this->getParentModule()->par("sensorUid").str();

//    std::cout << "[SENSOR] [ID: " << this->getParentModule()->getId() << "Recebeu pacote do drone "
//            << message->getSourceID() << ". [UUID: " << uuid << "]."
//            << endl;
    QuadrantMessage *payload = new QuadrantMessage();
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    payload->setSenderType(SENSOR);
    payload->setContent(payloadSize);
    payload->setUuids(this->uuid.c_str());

    CommunicationCommand *targetCommand = new CommunicationCommand();
//    targetCommand->setCommandType(CommunicationCommandType::SET_PAYLOAD);
    targetCommand->setCommandType(CommunicationCommandType::SET_TARGET);
    targetCommand->setTarget(pk->getName());
    targetCommand->setPayloadTemplate(payload);
    sendCommand(targetCommand);

//    if (message != nullptr) {
//        switch (message->getSenderType()) {
//        case DRONE: {
//            std::cout << "[SENSOR] Enviando mensagem para ID: \t"
//                    << message->getSourceID() << "\tUUID: \t"
//                    << payload->getUuids() << endl;
//            // Sets the correct target
//            CommunicationCommand *targetCommand = new CommunicationCommand();
//            targetCommand->setCommandType(CommunicationCommandType::SET_TARGET);
//            targetCommand->setTarget(pk->getName());
//            targetCommand->setPayloadTemplate(payload);
//            sendCommand(targetCommand);
//            break;
//        }
//        case SENSOR: {
//            // Sets the correct target
//            CommunicationCommand *targetCommand = new CommunicationCommand();
//            targetCommand->setCommandType(CommunicationCommandType::SET_TARGET);
//            targetCommand->setTarget(pk->getName());
//            targetCommand->setPayloadTemplate(payload);
//            sendCommand(targetCommand);
//            break;
//        }
//        case GROUND_STATION: {
//            break;
//        }
//        }
//    }
} /* namespace gradys_simulations */

// Redirects message to the proper function
void QuadrantSensorProtocol::handleMessage(cMessage *msg) {

    uuid = this->getParentModule()->par("sensorUid").str();
//    msg->getSenderModule()->getParentModule()->setU
//    std::cout << "\t " << this->getParentModule()->getId()
//            << ": simple SENSOR protocol message from " << this->uuid << "by "
//            << msg->getSenderModule()->getClassName() << "-id:"
//            << msg->getArrivalModuleId() << endl;
    QuadrantMessage *payload = new QuadrantMessage();
    payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
    payload->setSenderType(SENSOR);
    payload->setSourceID(this->getParentModule()->getId());
    payload->setUuids(this->uuid.c_str());
    payload->setContent(payloadSize);
    CommunicationCommand *command = new CommunicationCommand();
    command->setCommandType(SET_PAYLOAD);
    command->setPayloadTemplate(payload);
    sendCommand(command);
    Packet *packet = dynamic_cast<Packet*>(msg);
    if (packet != nullptr) {
//        QuadrantMessage *payload = dynamicPtrCast<const QuadrantMessage>(packet->peekAtBack());
//        payload->setUuids(this->uuid.c_str());
        this->handlePacket(packet);
    }
}

}
