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

package gradys_simulations.protocols.ground;

import gradys_simulations.protocols.base.CommunicationProtocolBase;

simple QuadrantGroundProtocol extends CommunicationProtocolBase
{
    parameters:
        @class(QuadrantGroundProtocol);
        @signal[dataLoad](type=long); // Declaration of dataLoad signal used to track current data load that the drone is carrying
        @signal[dronesIDs](type=string); // Declaration of dataLoad signal used to track the drones IDs
        @signal[oxenIDs](type=string); // Declaration of dataLoad signal used to track the oxen IDs
        @signal[oxenCoords](type=string); // Declaration of dataLoad signal used to track the oxen Coords
        string trackUuid = "01111111-1111-1111-1111-333333333333";
        string uuid = "01111111-1111-1111-1111-000000000000";
}
