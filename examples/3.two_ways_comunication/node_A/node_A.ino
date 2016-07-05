/*
 Standart Node Trasmition

 Ricardo Mena C
 ricardo@crcibernetica.com
 http://crcibernetica.com

 In this example we only have two nodes involved,
 here we send a messege to our partner and check
 if he respond us

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

uint8_t node_id = 8;      //This node id
uint8_t radio2_id = 1;    //The server ID
//uint8_t network = 199;  //Network Indentification
SimpleRFM radio1;         //SimpleRFM definition
String message = "";      //Packet to send
String msg = "";          //Received packets

void setup() {
//Default parameters in order
//uint8_t server_id, uint8_t network, const char encryptKey, boolean LowPower/HighPower, Frecuency
  radio1.initialize(node_id);
  Serial.begin(SERIAL_BAUD);
  Serial.println("This is your client");
  Serial.println("--------------------\n");
}//end setup

void loop() {
  node_a.receive(msg);//Save received messages
  if(msg != ""){//Check if msg is empty
	Serial.println(msg);//Print message received
  }//end if

  message = "HELLO NODE B!!!";
  //Parameter to send messages
  //node ID, message, length, maximum retries, maximum retrie wait time
  if(node_a.send(node_b_id, message)){
	  Serial.println(F("Packet delivered!"));
  }else{
	  Serial.println(F("Packet not receive"));
  }//end if
  delay(1000);
}//loop
