#include <SimpleRFM.h>

#define SERIAL_BAUD   115200

uint8_t radio1_id = 1;
uint8_t radio2_id = 2;    //The server ID
//uint8_t network = 199;  //Network Indentification
SimpleRFM radio2;         //SimpleRFM definition
String msg = "";          //Received packets
String message = "";      //Messages to send
uint32_t previousMillis = 0;

void setup() {
  //Default parameters in order
  //uint8_t server_id, uint8_t network, const char encryptKey, boolean LowPower/HighPower, Frecuency
  radio2.initialize(node_id);
  Serial.begin(SERIAL_BAUD);
  Serial.println(F("This is your radio 2"));
  Serial.println(F("-------------------\n"));
}//end setup

void loop(){
  message = "HELLO NODE 1";
  radio_message(millis(), 3000, message);
  radio2.receive(msg);
  if(msg != ""){//Check if msg is empty
	   Serial.println(msg);//Print message received
  }//end if
}//end loop

void radio_message(uint32_t timer, uint32_t interval, String message){
  if(timer - previousMillis > interval) {
  	if(radio2.send(radio1_id, message)){
  	  Serial.println("Packet delivered!");
  	}else{
  	  Serial.println("Packet not receive");
  	}//end if
    previousMillis = timer;
  }//end if
}//end radio_message
