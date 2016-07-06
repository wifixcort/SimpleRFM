/*
 Standart Gateway Trasmition

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

uint8_t radio2_id = 2;      //This node id
//uint8_t network = 199;  //Network Indentification
SimpleRFM radio2;         //SimpleRFM definition
String msg = "";          //Received packets

void setup() {
  //Default parameters in order
  //uint8_t server_id, uint8_t network, const char encryptKey, boolean LowPower/HighPower, Frecuency
  radio2.initialize(radio2_id);
  Serial.begin(SERIAL_BAUD);
  Serial.println(F("This is your radio 2"));
  Serial.println(F("-------------------\n"));
}//end setup

void loop(){
  radio2.receive(msg);
  if(msg != ""){//Check if msg is empty
	Serial.print(msg);//Print message received
	Serial.print("---> ");
	Serial.print("RSSI = ");
	Serial.println(radio2.rssi());
  }//end if
  Serial.flush();
}//end loop
