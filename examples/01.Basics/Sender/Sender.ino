#include <SimpleRFM.h>

#define NODE_ID 1 // each node in the network must have a unique nodeId (0-254)
#define RECEIVER 2 // the other radio should have a nodeId of 2
#define NETWORK 100 // all nodes need to have the same network (0-255)
#define ENCRYPT_KEY "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

#define RFM69_RST 8
#define LED 9

SimpleRFM radio;  //SimpleRFM definition

void setup() {

  Serial.begin(9600);
  
  radio.reset(RFM69_RST);

  radio.begin(NODE_ID, NETWORK, ENCRYPT_KEY, true);
}//end setup

void loop() {
  String message = "Hello";
  if(radio.send(RECEIVER, message, 200, 4)){
    radio.alert(LED);
	Serial.println("Packet delivered");
  }else{
	Serial.println("Packet not delivered");
  }//end if
  delay(1000);
}//loop
