//Joystick Button and XBee.
//Sends a y when button is pressed.
//Sends an @ right before LR is sent.
//Sends a ! right before UD is sent.

//NEED TO:
//join the UD and LR readings so that Robo_Ralph can move continuously rather tan have separated movements.
//Math so that the combination of joystick values sends only one value rather than two.

//Returns 0-1023 from analogRead
#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(0, 1); // RX, TX

//Constants
 int LRpin = 3;  //Needs to be analog-in.
 int UDpin = 2;  //Needs to be analog-in.
 int  ButtonPin = 2;
 int LEDPin = 0;
 char y = 'y';  //ASCII equiv. = 121
 char excl = '!';  //ASCII equiv. = 33
 char at = '@';  //ASCII equiv. = 64 
 
void setup()
{
 pinMode(LRpin, INPUT);
 pinMode(UDpin, INPUT);
 pinMode(LEDPin, OUTPUT);
 mySerial.begin(9600);
}

void loop()
{
  //Readings from ATtiny
 int Button = digitalRead(ButtonPin);
 int LR = analogRead(LRpin);
 int UD = analogRead(UDpin);
 

//This if else section sends a 'y' if button is pressed
                      //OR//
//it sends the values of LR and UD each preceeded by an @ or a ! respectively.


 if (Button == 1) //Button = 1 is auto mode
 {
   digitalWrite(LEDPin, LOW);                                //Turns the LED off. The LED on the controller goes high for Manual mode.
   mySerial.print(y);                                        //A char must be sent to be read by XB.Rx(Spin). A "y" tells the code to go into auto-mode.
   delay(100);
 }
 else                                                       
 {
   digitalWrite(LEDPin, HIGH);                               //If the LED connected to this pin is high, Robo_Ralph is in manual-mode.
   
   //Printing joystick positions to XBee.
   mySerial.print(at);                                      //A char must be sent to be read by XB.Rx  Use print not println
   mySerial.println(LR);                                    //Immediately after sending the "@", the value of the LR joystick position is sent.(need println!!!!!)
   delay(100);
 
   mySerial.print(excl);                                   //A char must be sent to be read by XB.Rx  Use print not println
   mySerial.println(UD);                                   //Immediately after sending the "!", the value of the UD joystick position is sent.
   delay(100); 
 }
}







