#include <SimpleRFM.h>

#define NODE_ID 2 // each node in the network must have a unique nodeId (0-254)
#define NETWORK 100 // all nodes need to have the same network (0-255)
#define ENCRYPT_KEY "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

#define RFM69_CS      8
#define RFM69_IRQ     3
#define RFM69_IRQN    3  // Pin 3 is IRQ 3!*/
#define RFM69_RST     4
#define IS_RFM69HCW   true
#define LED 13

SimpleRFM radio = SimpleRFM(RFM69_CS, RFM69_IRQ, IS_RFM69HCW, RFM69_IRQN);

void setup() {

  Serial.begin(9600);
  
  radio.reset(RFM69_RST);

  radio.begin(NODE_ID, NETWORK, ENCRYPT_KEY, true);
}//end setup

void loop(){
  String message;
  radio.receive(message);
  if(message != ""){
    radio.alert(LED);
    Serial.println(message);
  }//end if
}//end loop
