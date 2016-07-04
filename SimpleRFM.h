/*
  Easy handler for RFM69

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

#ifndef __SIMPLERFM_H__
#define __SIMPLERFM_H__

#include <Arduino.h>
#include <RFM69.h>    //https://www.github.com/lowpowerlab/rfm69
//#include "RFM69.h"   //https://www.github.com/lowpowerlab/rfm69
#include <SPI.h>

#ifdef __AVR_ATmega1284P__
  #define LED           15 // SimpleRFM MEGAs have LEDs on D15
  #define FLASH_SS      23 // and FLASH SS on D23
#elif defined(__arm__)
  #define LED          	13
  #define FLASH_SS      8
#else
  #define LED           9 // SimpleRFMs have LEDs on D9
  #define FLASH_SS      8 // and FLASH SS on D8
#endif

class SimpleRFM: public RFM69{// //RFM69::
  private:
	uint8_t node_id_receive;
	int8_t rssi;
	RFM69 radio;
	void alert(uint8_t t_delay);
  public:
	//    SimpleRFM(){};//Empty constructor
		virtual ~SimpleRFM();
		SimpleRFM();
		bool initialize(uint8_t node_Id, uint8_t netw_id = 100, const char *encryptK = "sampleEncryptKey", boolean mote_type=false, uint8_t frequency = RF69_915MHZ);
	boolean SimpleRFM_receive(String &msg);
	boolean SimpleRFM_send(uint8_t &gateway, String s_buffer, uint8_t retryWaitTime=200, uint8_t retries=2);// const void* buffe
	void SimpleRFM_sleep();
   uint8_t SimpleRFM_id_receive();
   int SimpleRFM_rssi();
};
#endif /* #ifndef __SimpleRFM_H__ */
