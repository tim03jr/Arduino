//Senses distance in inches with pololu IR sensor (max = 60")
//Output is not linear, so a regression equation is implemented.

int val;
int dist;

void setup() {
Serial.begin(115200);

}

void loop() {
  
  val = analogRead(0);//Read 
  dist = (187754 * pow(val, -1.51)) / 2.54;//Convert to inches via regression
  Serial.println(dist);//Print to monitor
  delay(10);
}
