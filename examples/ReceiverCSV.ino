#include <SimpleRFM.h>

#define NODEID 2 // each node in the network must have a unique nodeId (1-254)
#define NETWORK 100 // all nodes need to have the same network (1-254)
#define ENCRYPTKEY "sampleEncryptKey" // 16 characters, all nodes need to have the same encryptKey

SimpleRFM radio;

void setup() {

  Serial.begin(9600);

  radio.begin(NODEID, NETWORK, ENCRYPTKEY);
}//end setup

void loop() {
  String message = "";
  //create a String array of 4 to put the separated values
  // example message "7/15/2016 10:12:34,432,123,7.34"
  String values[4];
  
  radio.receive(message); // check radio for new messages

  if (message != "") {
    split(message, values, 4, ','); // a helper function to split the message into values[]
 
    String timestamp = values[0];
    int sensor1 = values[1].toInt(); //convert to integer
    int sensor2 = values[2].toInt(); //convert to integer
    float sensor3 = values[3].toFloat(); //convert to float

    Serial.println(timestamp);
    Serial.println(sensor1);
    Serial.println(sensor2);
    Serial.println(sensor3);

  }//end if
  delay(1000);
}//loop

}

void split(String &message, String *sArray, int size, char separator){
  for(int i = 0; i < size; i++){//Clean array
    sArray[i] = "";
  }//end for  
  int last_index = 0;//Remember last index in message
  for(int i = 0; i < size; i++){
    for(int j = last_index; j < message.length(); j++){
      if(message[j] == separator){
        last_index = j+1;
        break;
      }else{
        sArray[i] += message[j];
      }//end if
    }//end for
  }//end for
}//end split
