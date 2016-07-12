/*
 Simple receive example

 Bentley Born
 bentley@crcibernetica.com
 Ricardo Mena C
 ricardo@crcibernetica.com

 http://crcibernetica.com

 License
 **********************************************************************************
 This program is free software; you can redistribute it
 and/or modify it under the terms of the GNU General
 Public License as published by the Free Software
 Foundation; either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will
 be useful, but WITHOUT ANY WARRANTY; without even the
 implied warranty of MERCHANTABILITY or FITNESS FOR A
 PARTICULAR PURPOSE. See the GNU General Public
 License for more details.

 You should have received a copy of the GNU General
 Public License along with this program.
 If not, see <http://www.gnu.org/licenses/>.

 Licence can be viewed at
 http://www.gnu.org/licenses/gpl-3.0.txt

 Please maintain this license information along with authorship
 and copyright notices in any redistribution of this code
 **********************************************************************************
*/

#include <SimpleRFM.h>

#define nodeId 2 // each node in the network must have a unique nodeId (1-254)
#define network 100 // all nodes need to have the same network (1-254)
#define encryptKey "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

SimpleRFM radio;

void setup() {

  Serial.begin(9600);

  radio.begin(nodeId, network, encryptKey);
}//end setup

void loop(){
  String message;
  radio.receive(message);
  if(message !""){
    Serial.println(message);
  }//end if
}//end loop
