#include <SimpleRFM.h>

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
  String message;
  String title = "Multiple_readings";
  int read1 = digitalRead(12);
  float read2 = analogRead(A0);
  int read3 = random(100);

  //Send them as one message
  message = title +","+ String(read1) +","+ String(read2) +","+ String(read3);

  if(radio.send(RECEIVER, message)){
    radio.alert(LED);
    Serial.println("Packet delivered!");
  }else{
    Serial.println("Packet not delivered!");
  }//end if
  Serial.flush();
  delay(1000);
}//loop
