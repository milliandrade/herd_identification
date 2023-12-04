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
import inet.common.packet.chunk.Chunk;




namespace inet;


enum SenderType
{
  DRONE = 0;
  SENSOR = 1;
  GROUND_STATION = 2;
}

class QuadrantMessage extends FieldsChunk
{
    chunkLength = B(7); // Fixed chunk length
    SenderType senderType;
    int content = 0;
    int sourceID = -1;
    int destinationID = -1;
    int nextWaypointID = -1;
    int lastWaypointID = -1;
    int dataLength = 5;
    int leftNeighbours = 0;
    int rightNeighbours = 0;
    bool reversed = false;
	string drones;
	string uuids;
    string coords_by_ox;
	
}
