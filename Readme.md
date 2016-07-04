SimpleRFM network

The purpose is create a network of sensors with moteinos and raspberry Pi as a gateway / server.

The GenSens library simplifies the job of receiving and transmitting packets.

All transmitions are a C string type, only to send the sensor measurement
separated by ";" as many sensors like you want; the first value will be the node id that send the information.

The gateway is responsible for split the string to send to the Raspberry Pi emoncms platform.
