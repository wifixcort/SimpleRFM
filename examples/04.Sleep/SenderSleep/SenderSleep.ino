#include <SimpleRFM.h>
#include <LowPower.h>   //https://github.com/rocketscream/Low-Power

/*
  Note from Low-power github site
  External interrupt during standby on ATSAMD21G18A requires a patch to the Arduino SAMD Core
  in order for it to work. Fix is provided by this particular pull request.
*/

#define NODE_ID 1 // each node in the network must have a unique nodeId (1-254)
#define RECEIVER 2 // the other radio should have a nodeId of 2
#define NETWORK 100 // all nodes need to have the same network (1-254)
#define ENCRYPT_KEY "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

#define LED 8

SimpleRFM radio;  //SimpleRFM definition

void setup() {

  Serial.begin(9600);

  radio.begin(NODE_ID, NETWORK, ENCRYPT_KEY);
}//end setup

void loop() {
  String message = "Hello";
  if(radio.send(RECEIVER, message)){
    radio.alert(LED);
    Serial.println("Packet delivered!");
  }else{
    Serial.println("Packet not delivered!");
  }//end if
  /*You can use
	SLEEP_15MS, SLEEP_30MS, SLEEP_60MS, SLEEP_120MS, SLEEP_250MS, SLEEP_500MS,
	SLEEP_1S, SLEEP_2S, SLEEP_4S, SLEEP_8S, SLEEP_FOREVER
	See more examples if how use LowPower library
   */
  Serial.flush();
  radio.sleep();
  LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
}//loop
