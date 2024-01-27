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

#ifndef __gradys_simulations_HICASensorProtocol_H_
#define __gradys_simulations_HICASensorProtocol_H_

#include <omnetpp.h>
#include "../base/CommunicationProtocolBase.h"
#include "inet/common/geometry/common/Coord.h"

namespace gradys_simulations {

class HICASensorProtocol: public CommunicationProtocolBase {
    protected:
        int payloadSize;
        std::string uuid;

    protected:
        // Initialization function
        virtual void initialize(int stage) override;

        // Handles packet recieved from the drone
        virtual void handlePacket(Packet *pk) override;
        virtual void handleMessage(cMessage *msg) override;
};

} /* namespace gradys_simulations */

#endif /* __gradys_simulations_HICASensorProtocol_H_ */
