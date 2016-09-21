
unsigned int val = 252;

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  Serial.write(val);

}
