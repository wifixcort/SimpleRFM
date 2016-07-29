#include <SimpleRFM.h>

#define NODE_ID 2 // each node in the network must have a unique nodeId (0-254)
#define NETWORK 100 // all nodes need to have the same network (0-255)
#define ENCRYPT_KEY "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

SimpleRFM radio;  //SimpleRFM definition

void setup() {

  Serial.begin(9600);

  radio.begin(NODE_ID, NETWORK, ENCRYPT_KEY);
}//end setup

void loop(){
  String message;
  radio.receive(message);
  if(message != ""){
    Serial.println(message);
  }//end if
  Serial.flush();
}//end loop
