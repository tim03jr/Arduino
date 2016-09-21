//Sends encoder data to matlab

#include <Adafruit_MotorShield.h>
#include <Wire.h>
#include "utility/Adafruit_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
Adafruit_StepperMotor *myMotor = AFMS.getStepper(200,2);

void setup() {
  AFMS.begin();
  myMotor->setSpeed(50);//The -> is called the dereference command(Something having to do with pointers)
}

void loop() {
 
  myMotor->step(50,FORWARD, MICROSTEP);
  delay(1000);

}
