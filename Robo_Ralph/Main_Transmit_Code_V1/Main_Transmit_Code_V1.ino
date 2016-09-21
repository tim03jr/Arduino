//Sends characters to another ATtiny that then sends data via XBee and turns on corresponding LEDs.
//Sends a y when button is pressed.
//Sends an @ right before LR is sent.
//Sends a ! right before UD is sent.

//NEED TO:
//join the UD and LR readings so that Robo_Ralph can move continuously rather than have separated movements.
//Math so that the combination of joystick values sends only one value rather than two.

//Returns 0-1023 from analogRead
#include <SoftwareSerial.h>
SoftwareSerial mySerial = SoftwareSerial(1, 0); // (RX, TX)

//Constants
              //ANALOG PIN DESIGNATIONS ARE DIFFERENT FROM DIGITAL DESIGNATIONS.
 #define LRpin_3 3  //Needs to be analog-in. Actually pin 2(around the horn).
 #define UDpin_2 2  //Needs to be analog-in. Actually pin 3(around the horn).
 #define Auto_Manual_Button_Pin 2 //Actually pin 7(around the horn).
 #define Kinect_Button_Pin 1 //Actually pin 6 (around the horn).

 ////////////////////////////////////////Can I define these too???????????????????????
 char Auto_Manual_Mode = 'y';  //ASCII equiv. = 121
 char Kinect_Mode = 'k' //ASCII equiv?????????????????????????????
 char excl = '!';  //ASCII equiv. = 33
 char at = '@';  //ASCII equiv. = 64 
 
void setup()
{
 pinMode(LRpin, INPUT);
 pinMode(UDpin, INPUT);
 pinMode(Auto_Manual_Button_Pin, INPUT);
 pinMode(Kinect_Button_Pin, INPUT);
 mySerial.begin(9600);
}

void loop()
{
  //Readings
 int A_M_Read = digitalRead(Auto_Manual_Button_Pin);
 int K_Read = digitalRead(Kinect_Button_Pin);
 int LR = analogRead(LRpin);
 int UD = analogRead(UDpin);
 

//This if else section sends a 'y' if button is pressed
                      //OR//
//it sends the values of LR and UD each preceeded by an @ or a ! respectively.

 if (Kinect_Button_Pin == 1)
 {
  mySerial.print(Kinect_mode);
 }
 if (kinect_Button_Pin == 0)
 {
  if (Auto_Manual_Button_Pin == 1) //Button pressed = auto mode
  {
     mySerial.print(Auto_Manual_Mode);                                        //Maybe I can just put 'y' instead of a variable that holds it?????????????????????????????????????
     delay(100);
  }
  if  (Auto_Manual_Button_Pin == 0)                                                       
  {   
     //Printing joystick positions to XBee.
     mySerial.print(at);                                      //A char must be sent to be read by XB.Rx  Use print not println
     mySerial.println(LR);                                    //Immediately after sending the "@", the value of the LR joystick position is sent.
     delay(100);
 
     mySerial.print(excl);                                   //A char must be sent to be read by XB.Rx  Use print not println
     mySerial.println(UD);                                   //Immediately after sending the "!", the value of the UD joystick position is sent.
     delay(100); 
  }
 }
}







