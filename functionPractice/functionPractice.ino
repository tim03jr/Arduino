int a = 0;

void setup() {
 Serial.begin(9600);
}

void loop() {
  a = funct();
  Serial.println(a);
}

int funct(){
  return 5;
  }
