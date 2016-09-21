//This is the code that recieves the data from the other ATtiny and sends data out of the XBee.
//It also controls the lights on controller.


#define Manual_LED 2
#define Kinect_LED 1
#define Auto_LED 0
#define Recieve_Pin 4
#define Transmit_Pin 


#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(Recieve_Pin, Transmit_Pin); // (RX, TX)



void setup() 
{
   pinMode(Manual_LED, OUTPUT);
   pinMode(Auto_LED, OUTPUT);
   pinMode(Kinect_LED, OUTPUT);
   mySerial.begin(9600);
}

void loop() 
{
    //Reading from other ATtiny
 char ATtiny_Read = mySerial.read(Recieve_Pin);

 if (ATtiny_Read == 'k')  //Do I need the ''??????????????
 {
  mySerial.print('k');
 }
 else if (ATtiny_Read == 'y')
 {
  mySerail.print('y')
 }
 else 
}














