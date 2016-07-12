#SimpleRFM

The purpose of this library is to simplify the use of HopeRF RFM69 radios. This library uses the RFM69 library created by
Many radio libraries use char arrays and/or c strings which can be overly complex for many beginner programmers.
This library only sends an Arduino String object. There are only two functions: send() and receive().

##Functions

###send()

Send an Arduino String object to a specified node. The maximum size of the String is 61 bytes.

####Usage
boolean send(int nodeId, String message) //returns true if transmission successful

Example
```c++
#include <SimpleRFM.h>

#define nodeId 1 // each node in the network must have a unique nodeId (1-254)
#define receiver 2 
#define network 100 // all nodes need to have the same network (1-254)
#define encryptKey "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

SimpleRFM radio;

void setup() {
  
  Serial.begin(9600);

  radio.begin(nodeId, network, encryptKey);
}//end setup

void loop() {
  String message = "Hello";
  if(radio.send(receiver, message)){ //
	Serial.println("Packet delivered");
  }else{
	Serial.println("Packet not delivered");
  }//end if
  delay(1000);
}//loop
```

###receive()

Receives an Arduino String from a remote radio.

####Usage
receive(String message) // received String

Example
```c++
#include <SimpleRFM.h>

#define nodeId 2 // each node in the network must have a unique nodeId (1-254)
#define network 100 // all nodes need to have the same network (1-254)
#define encryptKey "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

SimpleRFM radio;

void setup() {
  
  Serial.begin(9600);

  radio.begin(nodeId, network, encryptKey);
}//end setup

void loop() {
String message;
  radio.receive(message);
  if(message !""){
    Serial.println(message);
  }
}//loop
```
