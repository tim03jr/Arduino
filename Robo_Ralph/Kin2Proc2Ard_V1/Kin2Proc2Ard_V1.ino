//Used in conjunction with the Serial_test processing sketch.
//Processing sends a 0, 90, or 180 and this sketch turns a led on or off.



#define Led_Pin  3

void setup() 
{
  pinMode(Led_Pin,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
    
  if(Serial.available())//Code stays here until data in buffer.
  {    
    int recieved = Serial.read();    
    if (recieved == 0)
    {
      digitalWrite(Led_Pin,HIGH);
    }
    if (recieved == 90)
    {
      digitalWrite(Led_Pin, LOW);
    }
  }
}



void blink(int Pin)
{
    digitalWrite(Pin,LOW);
    delay(100);
    digitalWrite(Pin, HIGH);
    delay(100);
}


