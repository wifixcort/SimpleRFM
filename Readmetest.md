#SimpleRFM

The purpose of this library is to simplify the use of HopeRF RFM69 radios. This library uses the RFM69 library created by
Many radio libraries use char arrays and/or c strings which can be overly complex for many beginner programmers.
This library only sends an Arduino String object. There are only two functions: send() and receive().

##Functions

###send()

Send a an Arduino String to a specified node.

####Usage
boolean send(int nodeId, String message) //returns true if transmission successful
```c++
send(2, "Hello"); //send "Hello" to node 2
```

####Returns boolean 

###receive()

Receives an Arduino String from a remote radio.

####Usage
receive(String message) // received String
