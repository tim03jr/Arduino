//Reads the time that a pin is high into "duration" then prints
//that value to the serial monitor.

#define signalReadPin  7
unsigned int duration;

void setup() {
  pinMode(signalReadPin, INPUT);
  Serial.begin(9600);
}
void loop() {
  duration = pulseIn(signalReadPin, HIGH);
  Serial.println(duration);
}
