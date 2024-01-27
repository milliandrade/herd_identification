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

#ifndef __gradys_simulations_HICADroneProtocol_H_
#define __gradys_simulations_HICADroneProtocol_H_

#include <omnetpp.h>
#include <list>
#include <vector>
#include "../base/CommunicationProtocolBase.h"
#include "../messages/network/HICAMessage_m.h"
#include "inet/common/geometry/common/Coord.h"
#include "inet/common/geometry/common/GeographicCoordinateSystem.h"


namespace gradys_simulations {


enum CommunicationStatus {
    FREE = 0, REQUESTING = 1, PAIRED = 2, COLLECTING = 3, PAIRED_FINISHED = 4
};

enum MobileMsgType {
    REQUEST_DATA = 0, RESPONSE_DATA = 1, SUGEST_DATA = 2, ACK_SUGEST = 3, NACK_SUGEST = 4, DECIDED_DATA=5, FOUND_SENSOR = 6, OTHER=7
};


class HICADroneProtocol: public CommunicationProtocolBase {
protected:
    simtime_t timeoutDuration;

    // Current tour recieved from telemetry
    std::vector<Coord> tour;

    int leftNeighbours = 0;
    int rightNeighbours = 0;

    // Communication status variable
    CommunicationStatus communicationStatus = FREE;

    // Current target
    int tentativeTarget = -1;
    // Previous target
    int lastTarget = -1;
    // Name of the current target (for addressing purposes)
    std::string tentativeTargetName;

    // Current imaginary data being carried
    int currentDataLoad = 0;
    // Stable data load to prevent data loss during pairing
    int stableDataLoad = currentDataLoad;

    // Last telemetry package received
    Telemetry currentTelemetry = Telemetry();
    Telemetry lastStableTelemetry = Telemetry();

//        list<int> dronesIDs = dronesIDs.begin();
    std::string dronesIDsList;
    std::string droneUuid;
    std::string trackUuid;


    HICAMessage lastPayload = HICAMessage();

protected:
    // Performs the initialization of our module. This is a function that most OMNeT++ modules will override
    virtual void initialize(int stage) override;
    // Called when the simulation finishes
    virtual void finish() override;
    // Saves telemetry recieved by mobility
//    virtual void handleTelemetry(gradys_simulations::Telemetry *telemetry) override;
    virtual void handleTelemetry(gradys_simulations::Telemetry *telemetry);
    // Gets called when a packet is recieved from the communication module
    virtual void handlePacket(Packet *pk) override;
//    virtual void handleMessage(cMessage *msg) override;
    // Helper function that updates packet content with the current collected data
    virtual bool isTimedout() override;
    // Resets parameters
    virtual void resetParameters();
    virtual void insertFoundDrone(std::string id);
    virtual void insertDronesIDs(std::vector<std::string> ids);
    virtual std::vector<std::string> getDronesIDs();
    virtual std::string getdronesIDsList();
    void refreshdronesIDs(std::string dronesList);
    virtual void insertFoundOx(std::string id);
    virtual void insertOxIDs(std::vector<std::string> ids);
    virtual std::vector<std::string> getOxIDs();
    virtual std::string getOxIDsList();
    void refreshOxIDs(std::string dronesList);
    void sendFoundOx(std::string oxID);
    void sendFinish(std::string oxID);
    std::string getDroneUuid();
    std::string getTrackUuid();
    void setDroneUuid(std::string dUuid);
    void setTrackUuid(std::string tUuid);
    bool isTracking();
    void checkMobility();
    std::string getTrackIdFile();
    void printDroneInformation();
    void sendFoundSensorLocation(int coord);
    virtual void goToTarget(int target);

private:
    // Updates payload that communication will send
    virtual void updatePayload();
    virtual void setTarget(const char *target);
public:
    simsignal_t dataLoadSignalID;
    simsignal_t dronesSignalID;
    simsignal_t oxSignalID;
    simsignal_t waypointSignalID;


    std::vector<std::string> dronesIDs;
    std::string oxenIDsList;
    std::string oxenCoordsList;
    std::vector<std::string> oxIDs;

//    std::vector<GeoCoord> tour = {
//                                GeoCoord(deg(-15.630068), deg(-48.096633), m(15)),
//                                GeoCoord(deg(-15.63182700), deg(-48.09663320), m(15)),
//                                GeoCoord(deg(-15.65180250), deg(-48.09903660), m(15)),
//                                GeoCoord(deg(-15.65453060), deg(-48.08101620), m(15)),
//                                GeoCoord(deg(-15.64453880), deg(-48.07508300), m(15)),
//                                GeoCoord(deg(-15.62453880), deg(-48.08108300), m(15)),
//                                GeoCoord(deg(-15.630068), deg(-48.997643), m(15)),
//                                GeoCoord(deg(-15.63005230), deg(-48.09668720), m(15)),
//                                GeoCoord(deg(-15.64452600), deg(-48.07502500), m(15)),
//                                GeoCoord(deg(-15.65452600), deg(-48.08102500), m(15)),
//                                GeoCoord(deg(-15.63002600), deg(-48.09662500), m(15)),
//                                GeoCoord(deg(-15.63245230), deg(-48.090033), m(15)),
//                                GeoCoord(deg(-15.63006800), deg(-48.09663300), m(15)),
//                                GeoCoord(deg(-15.62453880), deg(-48.09663300), m(15)),
//                                GeoCoord(deg(-15.64453880), deg(-48.08108300), m(15)),
//                                GeoCoord(deg(-15.65180250), deg(-48.08108300), m(15)),
//                                GeoCoord(deg(-15.65180250), deg(-48.09703660), m(15)),
//                                GeoCoord(deg(-15.63182700), deg(-48.09703660), m(15)),
//                                GeoCoord(deg(-15.63006800), deg(-48.09663300), m(15)),
//                                GeoCoord(deg(-15.62453880), deg(-48.08108300), m(15)),
//                                GeoCoord(deg(-15.64453880), deg(-48.07508300), m(15)),
//                                GeoCoord(deg(-15.65453060), deg(-48.08101620), m(15)),
//                                GeoCoord(deg(-15.65180250), deg(-48.09903660), m(15)),
//                                GeoCoord(deg(-15.63182700), deg(-48.09663320), m(15)),
//                                GeoCoord(deg(-15.63182600), deg(-48.10003300), m(15))
//                        };


//        int wayPointID = std::rand() % tour.size();
        std::list<int> received = {};

        bool hasWaited = false;
        bool hasVisitedWayPoint = false;
        int lastWayPoint;


};

} /* namespace gradys_simulations */

#endif /* __gradys_simulations_HICADroneProtocol_H_ */
