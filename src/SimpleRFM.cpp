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

SimpleRFM::SimpleRFM(uint8_t slaveSelectPin, uint8_t interruptPin, bool isRFM69HW, uint8_t interruptNum){
  this->_slaveSelectPin = slaveSelectPin;
  this->_interruptPin = interruptPin;
  this->_interruptNum = interruptNum;
  this->_mode = RF69_MODE_STANDBY;
  this->_promiscuousMode = false;
  this->_powerLevel = 31;
  #ifndef IS_RFM69HCW
   this->_isRFM69HW = isRFM69HW;
  #else
  this->_isRFM69HW = IS_RFM69HCW;
  #endif
}//end SimpleRFM

bool SimpleRFM::begin(uint8_t node_Id, uint8_t netw_id, const char *encryptK, boolean mote_type, uint8_t frequency){
  this->reset();
  bool radio = this->initialize(frequency, node_Id, netw_id);
  if(mote_type){//is this a high power SimpleRFM?
    this->setHighPower();
  }//end if
  this->encrypt(encryptK);//(const char*)
  return radio;
}//end initialize

SimpleRFM::~SimpleRFM(){
  delete(this);
}//end SimpleRFM

boolean SimpleRFM::receive(String &msg){
  msg = "";//Delete old string
  if (this->receiveDone()){
	  node_id_receive = this->SENDERID;//Save node id
	  for(uint8_t i = 0; i < this->DATALEN; i++){
	     msg += (char)this->DATA[i];//This is the data
  	}//end for
  	if (this->ACKRequested()){
  	  this->sendACK();
  	}//end if
	//  	alert(3);
  	return true;
  }//end if
  return false;
}//end receive

boolean SimpleRFM::send(uint8_t gateway, String s_buffer, uint8_t retryWaitTime, uint8_t retries){//retrines default 2, retriesWait default 40

  if (this->sendWithRetry(gateway, s_buffer.c_str(), s_buffer.length(), retries, retryWaitTime)){
	//  	alert(3);
  	return true;//ok!
  }else{
	   return false;//nothing!
  }//end if
}//end send

uint8_t SimpleRFM::id_receive(){
  return node_id_receive;
}//end id_receive

void SimpleRFM::split(String &message, String *sArray, int size, char separator){
  for(uint8_t i = 0; i < size; i++){//Clean array
    sArray[i] = "";
  }//end for
  uint8_t last_index = 0;//Remember last index in message
  for(uint8_t i = 0; i < size; i++){
    for(uint8_t j = last_index; j < message.length(); j++){
      if(message[j] == separator){
        last_index = j+1;
        break;
      }else{
        sArray[i] += message[j];
      }//end if
    }//end for
  }//end for
}

void SimpleRFM::alert(uint8_t led, uint8_t t_delay){
  pinMode(led, OUTPUT);
  digitalWrite(led,HIGH);
  delay(t_delay);
  digitalWrite(led,LOW);
}//end alert

void SimpleRFM::reset(uint8_t pinReset){
  pinMode(pinReset, OUTPUT);
  digitalWrite(pinReset, HIGH);
  delay(100);
  digitalWrite(pinReset, LOW);
  delay(100);  
}//end reset
