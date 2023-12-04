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

//QUADRANT
#ifndef __gradys_simulations_QuadrantSensorProtocol_H_
#define __gradys_simulations_QuadrantSensorProtocol_H_

#include <omnetpp.h>
#include "../base/CommunicationProtocolBase.h"
#include "../messages/network/QuadrantMessage_m.h"
#include <string>

namespace gradys_simulations {

class QuadrantGroundProtocol: public CommunicationProtocolBase {
protected:
    int content;
    std::string dronesIDs;
    std::string oxenIDs;
    std::string oxenCoords;
    std::string uuid;
    std::string trackUuid;

protected:
    virtual void initialize(int stage) override;
    virtual void handlePacket(Packet *pk) override;
    virtual std::string getdronesIDs();
    virtual void setdronesIDs(std::string drones);
    virtual std::string getOxenIDs();
    virtual void setOxenIDs(std::string oxen);
    virtual std::string getOxenCoords();
    virtual void setOxenCoords(std::string coords);
    virtual void setUuid(std::string gs_uuid);
    virtual std::string getUuid();
    virtual std::string getTrackUuid();
    virtual void setTrackUuid(std::string tUuid);


};

} /* namespace gradys_simulations */

#endif /* __gradys_simulations_QuadrantSensorProtocol_H_ */
