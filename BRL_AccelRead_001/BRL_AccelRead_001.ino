//Reads the analog output of an accelerometer (0-1023)
//Sends it out through serial
//
//Accelerometer takes 5v

unsigned int accelReading = 0;


void setup() {
  Serial.begin(115200);
  analogReference(EXTERNAL);//Sets 1023 = input to AREF

}

void loop() {
  accelReading = analogRead(1);//pin a1 is accel input
  int mapVal = map(accelReading, 1,1023,1,255);
  //Needs to be Serial.write not Serial.print
  //Serial.write sends 8-bit decimal value
  //Serial.print sends each digit as a byte
  Serial.write(mapVal);
}
