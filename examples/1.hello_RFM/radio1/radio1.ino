/*
 Simple transmit example

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

#define SERIAL_BAUD   115200

<<<<<<< HEAD
uint8_t radio1_id = 1;    //This node id
uint8_t radio2_id = 2;    //The server ID
//uint8_t network = 199;  //Network Indentification
uint8_t radio1_id = 1;      //This node id
uint8_t radio2_id = 2;    // Destination radio id
SimpleRFM radio1;         //SimpleRFM definition
String message = "";      //Packet to send

void setup() {
  //Default parameters in order
  //uint8_t server_id, uint8_t network, const char encryptKey, boolean LowPower/HighPower, Frecuency
  radio1.initialize(radio1_id);
  Serial.begin(SERIAL_BAUD);
  Serial.println("This is radio 1");
  Serial.println("---------------\n");
}//end setup

void loop() {
  message = "Hello this is radio 1!";
  //Parameter to send messages
  //server ID, message, maximum retry wait time, maximum retries
  if(radio1.send(radio2_id, message)){
	Serial.println("Packet delivered!");
  }else{
	Serial.println("Packet not received");
  }//end if
  delay(1000);
}//loop
