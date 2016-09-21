//Senses distance in inches of 5 pololu IR sensors (max = 60") and 5 HC-S04 USD sensors.
//Output or IR sensors is not linear, so a regression equation is implemented.
//NewPing library is used for USD sensors.

#include <NewPing.h>

#define maxDist 200   //This might affect the time that it waits// max is 500

int IR[5];      //IR array to store measurements
int US[3];      //Ultrasonic array to store measurements
double usDist;  //Using a double because of the conversion from cm to in ie: divide by 2.54
int irDist;     
byte i;

NewPing ultraSonic[5] = {   //Sensor object array. 
  NewPing(2,5,maxDist),
  NewPing(3,6,maxDist),
  NewPing(4,7,maxDist),   //Syntax: newPing name(triggerPin, EchoPin, maximum distance)
  NewPing(8,10,maxDist),  //dummy for now
  NewPing(9,11,maxDist),  //dummy for now
  };

void setup(){Serial.begin(115200);}

void loop() {
  
  //Read IRs
  for (i = 0;i <= 4; i++){
    IR[i] = analogRead(i);//Read 
  }

  //Read USs
  for (i = 0; i <= 2; i++){
    US[i] = ultraSonic[i].ping();
    }
    
  //Print
  for (i = 0; i <= 4; i++){
    irDist = (187754 * pow(IR[i], -1.51)) / 2.54;//Convert to inches via regression
    Serial.print("IR ");
    Serial.print(i);
    Serial.print(":\t");
    Serial.print(irDist);

    Serial.print("\t");
    
    usDist = (US[i] / US_ROUNDTRIP_CM)/2.54;
    Serial.print("US ");
    Serial.print(i);
    Serial.print(":\t");
    Serial.println(usDist);
    delay(100);
  }
}
