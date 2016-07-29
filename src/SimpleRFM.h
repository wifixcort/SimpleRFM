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

#if defined(__arm__)
#define RFM69_RST     4
#else
#define RFM69_RST     9
#endif

#if defined(__AVR_ATmega168__) || defined(__AVR_ATmega328P__) || defined(__AVR_ATmega88) || defined(__AVR_ATmega8__) || defined(__AVR_ATmega88__)
 #define RFM69_IRQ_PIN          2
 #define RFM69_IRQ_NUM          0
 #define FLASH_SS      8  //and FLASH SS on D8
#elif defined(__AVR_ATmega644P__) || defined(__AVR_ATmega1284P__)
 #define RFM69_IRQ_PIN          2
 #define RF69_IRQ_NUM          2
 #elif defined(__AVR_ATmega32U4__)
 #define RFM69_IRQ_PIN          3
 #define RFM69_IRQ_NUM          0
#elif defined(__arm__)
 // for Feather M0
 #define RFM69_SPI_CS      8
 #define RFM69_IRQ_PIN     3
 #define RFM69_IRQ_NUM    3  // Pin 3 is IRQ 3!
 #define IS_RFM69HCW   true // set to 'true' if you are using an RFM69HCW module
#else
 #define RFM69_IRQ_PIN          2
 #define RFM69_IRQ_NUM          0
#endif

#ifndef RFM69_SPI_CS
 #define RFM69_SPI_CS             SS
#endif

#ifdef __AVR_ATmega1284P__
#define FLASH_SS      23 // and FLASH SS on D23
#endif

class SimpleRFM: public RFM69{
 private:
   uint8_t node_id_receive;
 public:
  //    SimpleRFM(){};//Empty constructor
  virtual ~SimpleRFM();
  SimpleRFM(uint8_t slaveSelectPin=RFM69_SPI_CS, uint8_t interruptPin=RFM69_IRQ_PIN, bool isRFM69HW=false, uint8_t interruptNum=RFM69_IRQ_NUM);
  bool begin(uint8_t node_Id, uint8_t netw_id = 100, const char *encryptK = "sampleEncryptKey", boolean mote_type=false, uint8_t frequency = RF69_915MHZ);
  boolean receive(String &msg);
  boolean send(uint8_t gateway, String s_buffer, uint8_t retryWaitTime=200, uint8_t retries=2);// const void* buffe
  uint8_t id_receive();
  void split(String &message, String *sArray, int size, char separator);
  void alert(uint8_t led, uint8_t t_delay = 3);
  void reset(uint8_t pinReset = RFM69_RST);
};
#endif /* #ifndef __SimpleRFM_H__ */
