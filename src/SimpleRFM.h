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
#include "RFM69.h"    //https://www.github.com/lowpowerlab/rfm69
#include "RFM69config.h"
#include <SPI.h>

#define RF69_SPI_CS             SS

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega88) || defined(__AVR_ATmega8__) || defined(__AVR_ATmega88__)
 #define RF69_IRQ_PIN          2
 #define RF69_IRQ_NUM          0
 #define LED           13   //Moteinos have LEDs on D9
 #define FLASH_SS      8  //and FLASH SS on D8
#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega1284P__)
 #define RF69_IRQ_PIN          2
 #define RF69_IRQ_NUM          2
 #elif defined(__AVR_ATmega32U4__)
 #define RF69_IRQ_PIN          3
 #define RF69_IRQ_NUM          0
#elif defined(__arm__)
 #define RF69_IRQ_PIN          10
 #define RF69_IRQ_NUM          10
 #define LED           13  //Moteinos have LEDs on D9
#define FLASH_SS      8    //and FLASH SS on D8
#else
 #define RF69_IRQ_PIN          2
 #define RF69_IRQ_NUM          0
 #define LED           9  //Moteinos have LEDs on D9
 #define FLASH_SS      8  //and FLASH SS on D8
#endif

#ifdef __AVR_ATmega1284P__
#define LED           15 // Moteino MEGAs have LEDs on D15
#define FLASH_SS      23 // and FLASH SS on D23
#endif

class SimpleRFM: public RFM69{
 private:
  uint8_t node_id_receive;
  void alert(uint8_t t_delay);
 public:
  //    SimpleRFM(){};//Empty constructor
  virtual ~SimpleRFM();
  SimpleRFM(uint8_t slaveSelectPin=RF69_SPI_CS, uint8_t interruptPin=RF69_IRQ_PIN, bool isRFM69HW=false, uint8_t interruptNum=RF69_IRQ_NUM);
  bool begin(uint8_t node_Id, uint8_t netw_id = 100, const char *encryptK = "sampleEncryptKey", boolean mote_type=false, uint8_t frequency = RF69_915MHZ);
  boolean receive(String &msg);
  boolean send(uint8_t &gateway, String s_buffer, uint8_t retryWaitTime=200, uint8_t retries=2);// const void* buffe
  uint8_t id_receive();
};
#endif /* #ifndef __SimpleRFM_H__ */
