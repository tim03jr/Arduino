//BASIC INFO

//Blink----------------------------------------------------------------------------------------------------------------------------------------

/*
int led = 0;
void setup()
{
  pinMode(led, OUTPUT);
}
void loop()
{
 digitalWrite(led, HIGH);
delay(1000);
digitalWrite(led, LOW);
delay(1000);
}
*/


//Serial monitor and pushbutton----------------------------------------------------------------------------------------------------------------------------

/*
int pushButton = 2;
void setup()
{
 Serial.begin(9600);
 pinMode(pushButton, INPUT); 
}

void loop()
{
 int buttonState = digitalRead(pushButton);
 Serial.println(buttonState);
delay(10); 
}
*/

//XBee-------------------------------------------------------------------------------------------------------------------------------------------------

int  button = 2;
char y = 'Y';
char n = 'N';

void setup()
{
 Serial.begin(9600);
}

void loop()
{
 int val = digitalRead(button);
 if (val == 1) 
 {
   Serial.println('Y');
   delay(10);
 }
 else
 {
   Serial.println('N');
   delay(10);
 }
 
}







