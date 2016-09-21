//Senses distance in inches of five pololu IR sensor (max = 60")
//Output is not linear, so a regression equation is implemented.

int val[5];//reading array
int dist;
byte i;

void setup() {Serial.begin(115200);}

void loop() {
  
  //Read
  for (i = 0;i <= 4; i++){
    val[i] = analogRead(i);//Read 
  }

  //Print
  for (i = 0; i <= 4; i++){
    dist = (187754 * pow(val[i], -1.51)) / 2.54;//Convert to inches via regression
    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(":\t");
    Serial.println(dist);
    delay(100);
  }
  if(i >= 4){i = -1;}
}
