/*
 Standart Node Trasmition

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

#define NODE_ID 1 // each node in the network must have a unique nodeId (1-254)
#define RECEIVER 2 // the other radio should have a nodeId of 2
#define NETWORK 100 // all nodes need to have the same network (1-254)
#define ENCRYPT_KEY "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

SimpleRFM radio;         //SimpleRFM definition

void setup() {

  Serial.begin(9600);

  radio.begin(NODE_ID, NETWORK, ENCRYPT_KEY);
}//end setup

void loop() {
  String message = "Hello";
  if(radio.send(RECEIVER, message)){
	Serial.println("Packet delivered!");
  }else{
	Serial.println("Packet not receive");
  }//end if
  delay(1000);
}//loop
