//Gets distance measurements from 4 sensors and prints those distances to the serial port.

#include <NewPing.h>


//Trigger pins
#define TRIGGER_PIN2  2
#define TRIGGER_PIN3  3
#define TRIGGER_PIN4  4
#define TRIGGER_PIN5  5


//Echo pins
#define ECHO_PIN6     6
#define ECHO_PIN7     7
#define ECHO_PIN8     8
#define ECHO_PIN9     9


//Distances
#define MAX_DISTANCE 200//This might affect the time that it waits// max is 500


 
NewPing sonar0(TRIGGER_PIN2, ECHO_PIN6, MAX_DISTANCE);//Here we are initializing a class. When a class is initiallized, an initial bit of code is run initially. This bit of code is called the CONSTRUCTOR.//Must be fed an array for multiple sensors.
NewPing sonar1(TRIGGER_PIN3, ECHO_PIN7, MAX_DISTANCE);//sonar1 is the object name that we created. It can be whatever we want it to be.
NewPing sonar2(TRIGGER_PIN4, ECHO_PIN8, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN5, ECHO_PIN9, MAX_DISTANCE);

void setup() {
  Serial.begin(115200);
}
 
void loop() {


  //These can all be run in a loop to simplify the code.
  delay(50);
  int uS0 = sonar0.ping();
  Serial.print("Ping0: ");
  Serial.print(uS0 / US_ROUNDTRIP_CM);
  Serial.println("cm");

  delay(50);
  int uS1 = sonar1.ping();
  Serial.print("Ping1: ");
  Serial.print(uS1 / US_ROUNDTRIP_CM);
  Serial.println("cm");

  delay(50);
  int uS2 = sonar2.ping();
  Serial.print("Ping2: ");
  Serial.print(uS2 / US_ROUNDTRIP_CM);
  Serial.println("cm");

  delay(50);
  int uS3 = sonar3.ping();
  Serial.print("Ping3: ");
  Serial.print(uS3 / US_ROUNDTRIP_CM);
  Serial.println("cm");
}
