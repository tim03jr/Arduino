//Sends encoder data to matlab

#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);

unsigned long clck;
word  prevclck = 0;
byte  mSec = 2;
int val;

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  myMotor->run(FORWARD);
  myMotor->run(RELEASE);
  pinMode(3,INPUT);

  myMotor->setSpeed(125);
  myMotor->run(FORWARD);

  //Serial.write(Sec);
}

void loop() {
  
  clck = millis();//Current clock count in millisec
  
  if (clck - prevclck >= 100)//After 1/10 sec
  {
    prevclck = clck;
    Serial.write(mSec);//Write current time(milliSec) to serial port
    mSec++ ;//Count secs
    
  }
  
  val = digitalRead(4);
  Serial.write(val);//Use fread(arduiino obj) in matlab

}
