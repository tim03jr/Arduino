//Opperates a single HC-SR04 sensor
//Returns cm

#include <NewPing.h>

//For some reason, pins 0 and 1 do not work with this sensor.
#define TRIGGER_PIN  2
#define ECHO_PIN     5
#define MAX_DISTANCE 200
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
 
void setup() {
  Serial.begin(115200);
}
 
void loop() {
  delay(50);
  int uS = sonar.ping();
  Serial.print("Ping: ");
  Serial.print(uS / US_ROUNDTRIP_CM);//US_ROUNDTRIP_CM is a constant (57).
  Serial.println("cm");
}
