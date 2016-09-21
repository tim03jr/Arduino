//Sends encoder data to matlab
//Works with the Matlab program DataLogger.
//The CR sent with println acts as an end line.

#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);

unsigned long clck;
word  prevclck = 0;
byte  mSec = 2;
byte val;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  myMotor->run(FORWARD);
  myMotor->run(RELEASE);
  pinMode(3,INPUT);

  myMotor->setSpeed(100);
  myMotor->run(FORWARD);

  //Serial.write(Sec);
}

void loop() {
  
  Serial.flush();
  val = digitalRead(4);
  Serial.println(val);//Use fread(arduiino obj) in matlab
  delay(10);//To slow down the stream to Matlab
}
