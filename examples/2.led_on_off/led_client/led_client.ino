/*
Standart Node Trasmition Network v.2

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

#include <Moteino.h>
//-----Need to be declared to get  Moteino working------------
#include <RFM69.h> //https://github.com/LowPowerLab/RFM69
#include <SPI.h>
//------------------------------------------------------------

#define FREQUENCY     RF69_915MHZ
#define ENCRYPTKEY    "sampleEncryptKey"
#define SERIAL_BAUD   115200
#define PUSH_BUTTON   10

Moteino *client;          //Moteino definition
uint8_t node_id = 8;      //This node id
uint8_t server_id = 1;    //The server ID
uint8_t network = 199;    //Network Indentification
String pck = "";          //Packet to send

void setup() {
  pinMode(PUSH_BUTTON, INPUT_PULLUP);//Use a push button in pin 10
  client  = new Moteino(node_id, FREQUENCY, ENCRYPTKEY, network, false);//node#, freq, encryptKey, network, LowPower/HighPower(false/true)
  Serial.begin(SERIAL_BAUD);
  Serial.println(F("This is your client"));
  Serial.println(F("--------------------\n"));
}//end setup

void loop() {
  if(digitaRead(PUSH_BUTTON) == HIGH){
	pck = "LED ON";
  }else{
	pck = "LED OFF";
  }//end if
  //Parameter to send messages
  //server ID, message, length, maximum retries, maximum retrie wait time
  if(client->moteino_send(server_id, pck.c_str(), pck.length(), 2, 200)){
	  Serial.println(F("Packet delivered!"));
  }else{
	  Serial.println(F("Packet not receive"));
  }//end if
  delay(1000);
}//loop
