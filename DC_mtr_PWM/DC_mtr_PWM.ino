#define signalReadPin 7
#define motorPin 2
unsigned int duration;
unsigned int pause = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(signalReadPin, INPUT);
}

void loop() {
 // duration = pulseIn(signalReadPin, HIGH);
  //Serial.println(duration);
  digitalWrite(motorPin, HIGH);
  delayMicroseconds(pause);
  digitalWrite(motorPin, LOW);
  delayMicroseconds(pause);
  pause = (pause + 10);
  
  if (pause == 10000)
  {
    while(pause > 10)
    {
    //duration = pulseIn(signalReadPin, HIGH);
   // Serial.println(duration);   
    digitalWrite(motorPin, HIGH);
    delayMicroseconds(pause);
    digitalWrite(motorPin, LOW);
    delayMicroseconds(pause);
    pause = pause - 10;
    }
  }

}
