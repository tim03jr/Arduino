//This is for debuging the Robo-Ralph transmitter.

#define LR 0  //AnalogRead
#define UD 1  //AnalogRead
#define Manual_Led 0  //DigitalWrite
#define Auto_Led 1  //DigitalWrite
#define Kinect_Led 2  //DigitalWrite
#define AutoManual_Button 3  //DigitalRead
#define Kinect_Button 4   //DigitalRead


void setup() 
{
  Serial.begin(9600);

}

void loop() 
{ 
 // int LR_Value = analogRead(LR);
// // int UD_Value = analogRead(UD);
  
//  Serial.println(LR_Value);  //This needs to be terminated with a CR(ASCII 13)
 // delay(100);
    

  //Serial.println(UD_Value);  //This needs to be terminated with a CR(ASCII 13)
 // delay(100);    

digitalWrite(Kinect_Led, HIGH);
delay(100);
digitalWrite(Kinect_Led, LOW);
delay(100);
  
}






//void loop()
//{
// // if (digitalRead(AutoManual_Button) || digitalRead(Kinect_Button) == HIGH)
// // {
//   digitalWrite(0, HIGH);
//   digitalWrite(1, HIGH);
//   digitalWrite(2, HIGH);
////  }
////  else
////  {
////   digitalWrite(Kinect_Led, LOW);
////   delay(10);
////  }
//
//}

