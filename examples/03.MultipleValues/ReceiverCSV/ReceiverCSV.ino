#include <SimpleRFM.h>

#define NODEID 2 // each node in the network must have a unique nodeId (1-254)
#define NETWORK 100 // all nodes need to have the same network (1-254)
#define ENCRYPTKEY "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

#define LED 13

SimpleRFM radio;  //SimpleRFM definition

void setup() {

  Serial.begin(9600);

  radio.begin(NODEID, NETWORK, ENCRYPTKEY);
}//end setup

void loop() {
  String message = "";
  //create a String array of 4 to put the comma separated values
  // example message "7/15/2016 10:12:34,432,123,7.34"
  String values[4];

  radio.receive(message); // check radio for new messages

  if (message != "") {
    radio.alert(LED);
    radio.split(message, values, 4, ','); // a helper function to split the message into values[]

    String timestamp = values[0];
    int sensor1 = values[1].toInt(); //convert String to integer
    int sensor2 = values[2].toInt(); //convert String to integer
    float sensor3 = values[3].toFloat(); //convert String to float

    Serial.println(timestamp);
    Serial.println(sensor1);
    Serial.println(sensor2);
    Serial.println(sensor3);
  }//end if
  Serial.flush();
  delay(1000);
}//loop
