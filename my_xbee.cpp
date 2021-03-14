#include "my_xbee.h"

void sendXbee(String payload)
{
 	Serial1.println("XBEE:" + payload); // "z1;1234;0000" --> "XBEE:z1;1234;0000"
}

String receiveXbee()
{
	String incoming = "";
	if(Serial1.available())
	{
		 incoming = (Serial1.readString()).substring(5); // exemple "XBEE:s1" --> "s1"
		 Serial.println("received from rasp : " + incoming);
	}
	return incoming;
}

void startXbee()
{
    Serial1.begin(9600);
}

