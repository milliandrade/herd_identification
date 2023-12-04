package gradys_simulations;

import inet.node.inet.AdhocHost;
import inet.mobility.base.MovingMobilityBase;
import inet.common.geometry.common.OsgGeographicCoordinateSystem;
import inet.environment.common.PhysicalEnvironment;
import inet.mobility.contract.IMobility;

import gradys_simulations.protocols.base.IProtocol;
import gradys_simulations.mobility.failures.base.IFailureGenerator;

module FarmNode extends AdhocHost
{
    parameters:
        int internalMobNodeId = -1 @mutable;
        int simulationIndexOfFirstNode = 6;
        int nodeType = 171;
        int numFailures = default(0);

        string mobileNodeId = "0" @mutable;
        string trackUuid = "01111111-1111-1111-1111-333333333333" @mutable;
        bool tracking = false @mutable;
        
        int round=0;
        

        @class(FarmNode);

     submodules:

        protocol: <default("CommunicationProtocolBase")> like IProtocol {
            @display("p=237.825,75.6");
        }
        failures[numFailures]: <default("FailureGeneratorBase")> like IFailureGenerator {
            @display("p=626.85,39.375");
        }



}
