//This code is downloaded form the dot matrix instructable. 







#define time 4                                                          //Time in miliseconds between each motor's step
#define pentime 200                                                     //Time of the pulse in the pen motor
#define pulltime 6200                                                   //Time(in microseconds to allow a alrge range) of the pulse on the motor to pull the paper.

#define penPin 4                                                        //pen motor pin
#define paperPin 5                                                      //paper motor pin

#define StepperA1 9                                                     //stepper motor pins
#define StepperA2 10 
#define StepperB1 11 
#define StepperB2 12 

byte data;                                                              //Byte to receive and check data from computer. Can be 0-255.






void setup() {  
  
  Serial.begin(9600);                                                  //Start the Serial port.  

  pinMode(StepperA1, OUTPUT);                                          //Stepper motor pins as output
  pinMode(StepperA2, OUTPUT);
  pinMode(StepperB1, OUTPUT);
  pinMode(StepperB2, OUTPUT);

  pinMode(penPin,OUTPUT);                                              //Pen motor pin as a output
  pinMode(paperPin,OUTPUT);                                            //Paper motor pin as a output
  back(80);                                                            //Function call. Back returns the carriage to the begining.
}









void loop() {
  if(Serial.available()){                                             //Serial.available returns the number of bytes in the serial buffer(64 bytes total). Not putting a comparison operator in the if parameter is the same as: if (serial.available() != 0).
  while(Serial.available()>0){                                        //While there are bytes of data in the serial buffer continue.
      data=Serial.read();                                             //This line actually reads the data in the serial buffer and stores it in the byte "data".
      if(data==1){                                                    //
        dot();                                                        //Function call. Makes a dot.
        forward(1);                                                   //Function call. Advances one pixel (four steps).
      }

      if(data==0){
        forward(1);                                                   //If a zero was received, just avances.
      }
      if(data=='L'){                                                  //If a "L" was received, pull the paper to begin a new line.
        pullPaper();                                                  //Function call Pulls the paper.
        back(80);                                                     //Function call. return the carriage.
      }
    }
  }
}




//This code seems weird. The sequence of highs and lows causes the motor to run very rough. Also it seems to be half stepping(both coils are energized at the same time).
void forward(int number){                                           //Forward function, you can choose the number of steps when calling the function
  int i=0;                                                          //Stores the number of steps.
  
  while(i<number){
    digitalWrite(StepperA1, HIGH);                                  //This sequence is part of the basic algoritm to control a bipolar stepper motor.  
    digitalWrite(StepperA2, LOW);    
    digitalWrite(StepperB1, HIGH);     
    digitalWrite(StepperB2, LOW);     
    delay(time);                                                    //Wait. Time is defined.                
    digitalWrite(StepperA1, HIGH);    
    digitalWrite(StepperA2, LOW);     
    digitalWrite(StepperB1, LOW);    
    digitalWrite(StepperB2, HIGH);     
    delay(time);
    digitalWrite(StepperA1, LOW);    
    digitalWrite(StepperA2, HIGH);     
    digitalWrite(StepperB1, LOW);    
    digitalWrite(StepperB2, HIGH);     
    delay(time);
    digitalWrite(StepperA1, LOW);    
    digitalWrite(StepperA2, HIGH);     
    digitalWrite(StepperB1, HIGH);    
    digitalWrite(StepperB2, LOW);     
    delay(time);
    i++;
  }
  digitalWrite(StepperA1, LOW);    
  digitalWrite(StepperA2, LOW);     
  digitalWrite(StepperB1, LOW);    
  digitalWrite(StepperB2, LOW);     

}

void back(int number){                                               //Reverse of forward sequence.
  int i=0;
  while(i<number){
    digitalWrite(StepperA1, LOW);    
    digitalWrite(StepperA2, HIGH);     
    digitalWrite(StepperB1, HIGH);    
    digitalWrite(StepperB2, LOW);     
    delay(time);

    digitalWrite(StepperA1, LOW);    
    digitalWrite(StepperA2, HIGH);     
    digitalWrite(StepperB1, LOW);    
    digitalWrite(StepperB2, HIGH);     
    delay(time);

    digitalWrite(StepperA1, HIGH);    
    digitalWrite(StepperA2, LOW);     
    digitalWrite(StepperB1, LOW);    
    digitalWrite(StepperB2, HIGH);     
    delay(time);

    digitalWrite(StepperA1, HIGH);    
    digitalWrite(StepperA2, LOW);     
    digitalWrite(StepperB1, HIGH);    
    digitalWrite(StepperB2, LOW);     
    delay(time);                 

    i++;
  }
  digitalWrite(StepperA1, LOW);    
  digitalWrite(StepperA2, LOW);     
  digitalWrite(StepperB1, LOW);    
  digitalWrite(StepperB2, LOW);     

}



void dot(void){                                                    //actives the pen motor for some time
  digitalWrite(penPin,HIGH);
  delay(pentime);
  digitalWrite(penPin,LOW);
}

void pen(void){                                                   //This functions can be used if you want to make lines instead of dots,
  digitalWrite(penPin,HIGH);                                      
}                                      //
void nopen(void){                      //
  digitalWrite(penPin,LOW);            //
}                                      //

void pullPaper(void){                                             //Function to pull the paper
  digitalWrite(paperPin,HIGH);
  delayMicroseconds(pulltime);
  digitalWrite(paperPin,LOW);
}





