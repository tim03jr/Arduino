//Sending data to matlab


int i = 0;//Data type limits magnitude of output.
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(i);//Use fread(arduiino obj) in matlab
  i++;

  if (i==200)
  {
    i = 0;
  }
}
