#include "inet/common/INETDefs.h"


#ifndef __FARMNODE_H_
#define __FARMNODE_H_

#include <omnetpp.h>
//#include <cModule.h>
#include "inet/common/ModuleAccess.h"
#include "inet/common/packet/Packet.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "inet/transportlayer/contract/udp/UdpControlInfo_m.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include "inet/applications/base/ApplicationBase.h"
#include "inet/transportlayer/contract/udp/UdpSocket.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using std::cout; using std::endl;
using std::string; using std::reverse;


using namespace omnetpp;
using namespace inet;

namespace gradys_simulations {

//enum mobileNodeType { sensor = 1, uav = 2, baseStation = 3, missing = 171 };

class FarmNode : public cModule  {
  protected:
    virtual void initialize() override;
    virtual void handleMessage(cMessage *msg);
  public:
    int processMessage(inet::Packet *msg);
    string generateNextPacketToSend();
    int internalMobNodeId = -1;
    string mobileNodeId = "0";
    string trackUUid = "01111111-1111-1111-1111-333333333333";
    long sentMsgs = -1;

    int numSensores=0;
    bool tracking=false;

    int round = 0;


    void actualizeSensorsUid(cModule *module);
    void actualizeDronesUid(cModule *module);
    void initLuaMobileNode();
    void runLua();
    string getUid(int qnt);
    string getTrackUuid();
    void setTrackUuid(std::string uuid);
    void getTracking();
    void incrementRound();
    int getRound();
  //  mobileNodeType myType = missing;

};

} //namespace
#endif
