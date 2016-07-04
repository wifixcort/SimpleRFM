/*
  Easy handler for   RFM69

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

#include "SimpleRFM.h"


SimpleRFM::SimpleRFM(){

}//end SimpleRFM

bool SimpleRFM::initialize(uint8_t node_Id, uint8_t netw_id, const char *encryptK, boolean mote_type, uint8_t frequency){
  bool radio = RFM69::initialize(frequency, node_Id, netw_id);
  if(mote_type){//is this a high power SimpleRFM?
	RFM69::setHighPower();
  }//end if
  RFM69::encrypt(encryptK);//(const char*)
  return radio;
}

SimpleRFM::~SimpleRFM(){
//  delete(this);
}//end SimpleRFM

boolean SimpleRFM::SimpleRFM_receive(String &msg){
  msg = "";//Delete old string
  if (RFM69::receiveDone()){
	node_id_receive = RFM69::SENDERID;//Save node id
	rssi = RFM69::RSSI;//Save node rssi
	for(uint8_t i = 0; i < RFM69::DATALEN; i++){
	  msg += (char)RFM69::DATA[i];//This is the data
	}//end for
	if (RFM69::ACKRequested()){
	  RFM69::sendACK();
	}//end if
	alert(3);
	return true;
  }//end if
  return false;
}//end SimpleRFM_receive

boolean SimpleRFM::SimpleRFM_send(uint8_t &gateway, String s_buffer, uint8_t retryWaitTime, uint8_t retries){//retrines default 2, retriesWait default 40
  
  if (RFM69::sendWithRetry(gateway, s_buffer.c_str(), s_buffer.length(), retries, retryWaitTime)){
	alert(3);
	return true;//ok!
  }else{
	return false;//nothing!
  }//end if
}//end SimpleRFM_send

uint8_t SimpleRFM::SimpleRFM_id_receive(){
  return node_id_receive;
}//end SimpleRFM_id_receive

void SimpleRFM::SimpleRFM_sleep(){
RFM69::sleep();
}//end mote_sleep


void SimpleRFM::alert(uint8_t t_delay){
  pinMode(LED, OUTPUT);
  digitalWrite(LED,HIGH);
  delay(t_delay);
  digitalWrite(LED,LOW);
}//end alert_incomming

int SimpleRFM::SimpleRFM_rssi(){
    return rssi;
}//end SimpleRFM_rssi
