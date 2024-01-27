#include <omnetpp.h>
#include "FarmNode.h"
#include "stdlib.h"
#include <time.h>
#include "FarmNode.h"
#include "MobileSensorNode.h"

#include <iostream>
#include <fstream>
#include <string>

namespace gradys_simulations {

Register_Class(FarmNode);
//Define_Module(FarmNode);

void FarmNode::initialize() {

    // TO-DO: these ID shaw be UUID as in network
//    internalMobNodeId = this->getId().par("simulationIndexOfFirstNode").intValue() + 1;
//    par("internalMobNodeId").setIntValue(internalMobNodeId);

//this->myType = static_cast<mobileNodeType>(par("nodeType").intValue());
    std::cout << "[FARM] initialization of internalMobNodeId: "
            << internalMobNodeId << " Class " << this->getClassName() << "."
            << endl;

    actualizeSensorsUid(this->getParentModule());
    actualizeDronesUid(this->getParentModule());
//    getTracking();
}

int FarmNode::processMessage(inet::Packet *msg) {

    // O getname � o payload
    std::cout << "UAV-" << internalMobNodeId << " received: " << msg->getName()
            << endl;

    return 1;

}

string FarmNode::generateNextPacketToSend() {

    std::ostringstream payload;

    payload << "Hi from " << "UAV-" << internalMobNodeId << "{" << ++sentMsgs
            << "}" << endl;

    return payload.str().c_str();
}
;

void FarmNode::handleMessage(cMessage *msg) {

    std::cout << " FarmNode::handleMessage: " << msg << endl;

}

void init1() {
    // find factory object
    cModuleType *moduleType = cModuleType::get("projeto.MobileSensorNode");

    // create (possibly compound) module and build its submodules (if any)

}

void FarmNode::actualizeSensorsUid(cModule *module) {
    numSensores = module->par("numSensors");
    int i = 0;//11;
    int qnt = numSensores;// + i;
    std::string tmpUid = "default ID";
    //read bd and get the first numSensors oxen

//    std::ifstream myfile("tmp_uuid.txt");
    std::ifstream myfile("/home/lac/workspace/gradys-simulations/showcases/sim/quadrant_simulation/tmp_uuid.txt");


    if (myfile.is_open()) {
        while (myfile) {
            std::getline(myfile, tmpUid);
            if (i < qnt) {
                cModule *tmp = module->getSubmodule("sensors", i);
                tmp->par("sensorUid") = tmpUid;
                std::cout <<"----------------- ID: \t" << i <<endl;
                std::cout <<"----------------- UUID: \t" << tmpUid <<endl;
                i++;
            }
        }
    }
}

void FarmNode::actualizeDronesUid(cModule *module) {
//    int nDrones = 4;
    int nDrones = 8;
    int i = 0;//11;
    int qnt = numSensores;// + i;
    std::string tmpUid = "default ID";
    std::string grazeId = "";
    std::string track = "";

    //read bd and get the first numSensors oxen

    std::ifstream myfile("tmp_drones_uuid.txt");

    if (myfile.is_open()) {
        std::getline(myfile, grazeId);
        std::getline(myfile, track);
        std::getline(myfile, tmpUid);
        while (myfile) {
            if (i < qnt) {
                cModule *tmp = module->getSubmodule("quads", i);
                tmp->par("mobileNodeUUid") = tmpUid;
                tmp->par("trackingUUid") = grazeId;
                std::cout <<"---QUADS [" << i << "]\t UUID: \t" << tmpUid <<endl;
                i++;
            }
            std::getline(myfile, tmpUid);
        }
    }
    if (track == "0"){
        //mobilidade dos drones = parada
        this->par("tracking") = false;
        this->tracking = false;
    }else{
        //mobilidade dos drones = tracking
        this->par("tracking") = true;
                this->tracking = true;
        this->setTrackUuid(grazeId);
    }
    std::cout << "finalizou a atualiza��o dos ids dos quads" << endl;
}

void FarmNode::getTracking(){
//    std::string cmd = "java -jar ";
//        cmd = cmd + "C:\\Users\\mille\\git\\repository2\\ICMU-T1-rastreamento-cliente\\target\\ICMU-T2-GroundNode-0.9-jar-with-dependencies.jar";
//
//        char buffer[128];
//        std::string result = "";
//        FILE *pipe = _popen(cmd.c_str(), "r");
//        if (!pipe)
//            throw std::runtime_error("popen() failed!");
//        try {
//            while (fgets(buffer, sizeof buffer, pipe) != NULL) {
//                result += buffer;
//            }
//        } catch (...) {
//            _pclose(pipe);
//            throw;
//        }
//        std::cout << result << endl;
//        _pclose(pipe);
}

string FarmNode::getUid(int qnt) {
    std::string ids = "";
    std::ifstream myfile("tmp_uuid.txt");
    string myline;
    int i = 0;
    if (myfile.is_open()) {
        while (myfile) {
            std::getline(myfile, myline);
            if (i < qnt) {
                ids = ids + "\n" + myline;
                i++;
            }
        }
    }
    return ids;
}

void FarmNode::initLuaMobileNode() {

}

//MYSQL conection(){
//    MYSQL *conn = mysql_init(NULL);
//
//      if (mysql_real_connect(conn, "localhost", "root", "1234",
//              NULL, 0, NULL, 0) == NULL)
//      {
//          fprintf(stderr, "%s\n", mysql_error(conn));
//          mysql_close(conn);
//          exit(1);
//      }
//
//      if (mysql_query(conn, "CREATE DATABASE TWDATA"))
//      {
//          fprintf(stderr, "%s\n", mysql_error(conn));
//          mysql_close(conn);
//          exit(1);
//      }
//
//      mysql_close(conn);
//      exit(0);
//      return conn;
//}

void FarmNode::runLua() {
//    STARTUPINFO info = { sizeof(info) };
//    PROCESS_INFORMATION processInfo;
//    if ( CreateProcess("cmd.exe", "/c commands.cmd", NULL, NULL, TRUE, 0, NULL,
//    NULL, &info, &processInfo)) {
//        WaitForSingleObject(processInfo.hProcess, INFINITE);
//        CloseHandle(processInfo.hProcess);
//        CloseHandle(processInfo.hThread);
//    }
}

string FarmNode::getTrackUuid(){
    return this->trackUUid;
}

void FarmNode::setTrackUuid(std::string uuid){
this->trackUUid = uuid;
}

void FarmNode::incrementRound(){
    this->round++;
}
    int FarmNode::getRound(){
        return this->round;
    }

} //namespace
