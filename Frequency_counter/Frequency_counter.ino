//Downloaded from arduino forum
//Measures frequency via an interrupt
//prints RPM to serial



// Frequency counter sketch, for measuring frequencies low enough to execute an interrupt for each cycle
// Connect the frequency source to the INT0 pin (digital pin 2 on an Arduino Uno)

volatile unsigned long firstPulseTime;//Always good to use volitile for variables in ISR's
volatile unsigned long lastPulseTime;
volatile unsigned long numPulses;

void isr()
{
 unsigned long now = micros();
 if (numPulses == 1)
 {
   firstPulseTime = now;
 }
 else
 {
   lastPulseTime = now;
 }
 ++numPulses;//Add one and return that new value
}

void setup()
{
 Serial.begin(19200);    // this is here so that we can print the result
 pinMode(3, OUTPUT);     // put a PWM signal on pin 3, then we can connect pin 3 to pin 2 to test the counter
 analogWrite(3, 255);
}

// Measure the frequency over the specified sample time in milliseconds, returning the frequency in Hz
float readFrequency(unsigned int sampleTime)
{
 numPulses = 0;                      // prime the system to start a new reading
 attachInterrupt(0, isr, RISING);    // enable the interrupt
 delay(sampleTime);
 detachInterrupt(0);
 return (numPulses < 3) ? 0 : (1000000.0 * (float)(numPulses - 2))/(float)(lastPulseTime - firstPulseTime);
}

void loop()
{
 float freq = readFrequency(100);
 float rpm = freq/9;
 Serial.println(rpm);
 //delay(10);
}
