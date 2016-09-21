//XBee. Sends the status of a button to another XBee.-----------------------------------------------------------------------------------------------------------------------------
//Modified version of XBeeTransmitter to work with ATtiny
//Voltage divider must be set up so that the input to ATtiny is 
//avove 2.7 V.

#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(0, 1); // RX, TX
int  ButtonPin = 2;
char y = 'Y';
char n = 'N';


void setup()
{
  pinMode(0,OUTPUT);
  mySerial.begin(9600);
}

void loop()
{
 int val = digitalRead(ButtonPin);
 if (val == 1) 
 {
   mySerial.print(y);
   delay(10);
 }
 else
 {
   mySerial.print(n);
   delay(10);
 }
 
}


