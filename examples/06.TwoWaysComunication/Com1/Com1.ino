#include <SimpleRFM.h>

#define SERIAL_BAUD   115200

uint8_t radio1_id = 1;    //This node id
uint8_t radio2_id = 2;    //The server ID
//uint8_t network = 199;  //Network Indentification
SimpleRFM radio1;         //SimpleRFM definition
String message = "";      //Packet to send
String msg = "";          //Messages to send
uint32_t previousMillis = 0;

void setup() {
  //Default parameters in order
  //uint8_t server_id, uint8_t network, const char encryptKey, boolean LowPower/HighPower, Frecuency
  radio1.initialize(radio1_id);
  Serial.begin(SERIAL_BAUD);
  Serial.println("This is your radio 1");
  Serial.println("--------------------\n");
}//end setup

void loop() {
  message = "HELLO NODE 2";
  radio_message(millis(), 5000, message);
  radio1.receive(msg);
  if(msg != ""){//Check if msg is empty
	   Serial.println(msg);//Print message received
  }//end if
}//loop

void radio_message(uint32_t timer, uint32_t interval, String message){
  if(timer - previousMillis > interval) {
  	if(radio1.send(radio2_id, message)){
  	  Serial.println("Packet delivered!");
  	}else{
  	  Serial.println("Packet not receive");
  	}//end if
    previousMillis = timer;
  }//end if
}//end radio_message
