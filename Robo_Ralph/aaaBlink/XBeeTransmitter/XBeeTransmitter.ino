//XBee. Sends the status of a button to another XBee.-----------------------------------------------------------------------------------------------------------------------------

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


