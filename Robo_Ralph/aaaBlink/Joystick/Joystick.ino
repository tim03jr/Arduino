//Joystick
//Reads Joystick values and sends them via mySerial.
//Returns 0-1023 from analogRead

#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(0, 1); // RX, TX

 //Constants
 int LRpin = 3;
 int UDpin = 4;
 
void setup()
{
  pinMode(LRpin, INPUT);
  pinMode(UDpin, INPUT);
  mySerial.begin(9600);
}

void loop()
{
  int LR = analogRead(LRpin);
  delay(10);
  int UD = analogRead(UDpin);
  delay(10);

  mySerial.println(LR);
  //Serial.print(UD);
  delay(1000); 
}

