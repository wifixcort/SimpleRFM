#include <SimpleRFM.h>

#define NODE_ID 1 // each node in the network must have a unique nodeId (0-254)
#define RECEIVER 2 // the other radio should have a nodeId of 2
#define NETWORK 100 // all nodes need to have the same network (0-255)
#define ENCRYPT_KEY "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

SimpleRFM radio;  //SimpleRFM definition

void setup() {

  Serial.begin(9600);

  radio.begin(NODE_ID, NETWORK, ENCRYPT_KEY);
}//end setup

void loop() {
  String message = "Hello";
  if(radio.send(RECEIVER, message)){
    Serial.print("Packet delivered! RSSI = ");
    Serial.println(radio.RSSI);
  }else{
    Serial.println("Packet not delivered!");
  }//end if
  Serial.flush();
  delay(1000);
}//loop
