//This code is for the Robo-Ralph transmitter. It uses an ATmega16 running at 8MHz.

//Sends a "k" for Kinect mode or a "y" for Auto-mode or a "!" and a "@" followed by a numberic values representing joystick position.  

#define LR 0  //AnalogRead
#define UD 1  //AnalogRead
#define Manual_Led 0  //DigitalWrite
#define Auto_Led 1  //DigitalWrite
#define Kinect_Led 2  //DigitalWrite
#define AutoManual_Button 3  //DigitalRead
#define Kinect_Button 4   //DigitalRead

void setup() 
{
  Serial.begin(9600);                                                                                         //Start Serial com.
}

void loop() 
{  
  int LR_Value = analogRead(LR);                                                                              //Read Joystick and buttons.
  int UD_Value = analogRead(UD);
  int AutoManual_Button_Reading = digitalRead(AutoManual_Button);
  int Kinect_Button_Reading = digitalRead(Kinect_Button);

if (Kinect_Button_Reading == HIGH)                                                                            //If Kinect button is pressed go into Kinect mode. 
{
  digitalWrite(Manual_Led, LOW);
  digitalWrite(Auto_Led, LOW);
  digitalWrite(Kinect_Led, HIGH);
  Serial.print('k');  //ASCII equiv = 107
  delay(100);
}

if(Kinect_Button_Reading == LOW)                                                                             //Only if Kinect button is low, do everything else.
{ 
  if (AutoManual_Button_Reading == HIGH)                                                                     //HIGH is for auto mode
  {
    digitalWrite(Manual_Led, LOW);
    digitalWrite(Auto_Led, HIGH);
    digitalWrite(Kinect_Led, LOW);
    Serial.print('y');  //ASCII equiv = 121
    delay(100);  
  }  
  if (AutoManual_Button_Reading == LOW)                                                                     //LOW is for manual mode
  {
    digitalWrite(Manual_Led, HIGH);
    digitalWrite(Auto_Led, LOW);
    digitalWrite(Kinect_Led, LOW);
    
    Serial.print('@');  //ASCII equiv = 64
    Serial.println(LR_Value);                                                                              //This needs to be terminated with a CR(ASCII 13)
    delay(100);
    
    Serial.print('!');  //ASCII equiv = 33
    Serial.println(UD_Value);                                                                              //This needs to be terminated with a CR(ASCII 13)
    delay(100);    
  }
 }
}
