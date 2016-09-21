//Joystick Button and XBee.
//Sends all three values to receiver continuously.
#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(0, 1); // RX, TX

//Constants
 int LRpin = 3;//Needs to be analog-in.
 int UDpin = 4;
 int  ButtonPin = 2;

void setup()
{
 pinMode(LRpin, INPUT);
 pinMode(UDpin, INPUT);
 pinMode(0,OUTPUT);
 mySerial.begin(9600);
}

void loop()          //If Button = 1 send the value of button to receiver 10 times. Wait 1/10 sec, read Button again(Button should = 0). Then repeatedly send values of LR and UD to receiver until button = 1 again.
                     //When Button = 1 again, start code over again.
{
 int Button = digitalRead(ButtonPin);
 
 //int LR = analogRead(LRpin);
 //delay(100);
 //mySerial.print(LR);
       
 int UD = analogRead(UDpin);
 delay(100);      
 mySerial.print(UD);
 
 while (Button == 1) 
 {
     mySerial.print(Button);//First print value of Button several times to make sure it gets there.
     Button = digitalRead(ButtonPin);
     delay(100); 
 }
   
   
    
 
}
