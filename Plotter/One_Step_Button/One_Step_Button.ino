//The purpose of this code is to allow finer resolution that what the original instructables code offers.
//That code makes four steps every pixel. The program in the loop function will help to make only one step per pixel.

//Slow_Steps function: Takes single steps in 8 step groups.
//Fast function: 
//Loop function: Push button initiates a single step.

//INFO:
//Voltage powering motor must be above 5V. At 5V, motors stutter.
//Top stepper has 380 steps(380 pixel resolution)
//Bottom stepper has 254 steps
//A 1 millisecond delay after coil is energized and after coil is set low produces the smoothest sound and the fastest speed.
//Enable_X or Enable_Y must be high while executing commands.


//NEEDED:
//Need to figure out which coil is first.(Initial position). 
//There is no motion until the energized coil reaches the position of the internal magnet.


//Pins
#define StepperA1 2                                 
#define StepperA2 3 
#define StepperB1 4 
#define StepperB2 5 
#define Enable_X 6
#define Enable_Y 7
#define Button_1 10
#define Button_2 11
#define time 1

byte Button_Read_1;
byte Button_Read_2;
int Button_Count = 0;

void setup() {
  pinMode(StepperA1, OUTPUT);
  pinMode(StepperA2, OUTPUT);
  pinMode(StepperB1, OUTPUT);
  pinMode(StepperB2, OUTPUT);
  pinMode(Enable_X,  OUTPUT);
  pinMode(Enable_Y,  OUTPUT);
  pinMode(Button_1, INPUT);
  pinMode(Button_2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);                            //Here for de-bugging.
}

void loop() {
 
//  Button_Read_2 = digitalRead(Button_2);
//  while(digitalRead(Button_2) == 1);           //This is meant to pause the code until the button is released.
//    
//    if (Button_Read_2 == 1) {                  //If status of Button_Read_1 is 1 then add to Button_Count.
//    Button_Count++;
//    }
//    
//   digitalWrite(Enable_Y, HIGH);
//   
//   switch(Button_Count){
//  
//   case 1:
//    digitalWrite(StepperA1, HIGH); 
//    delay(10*time); 
//    digitalWrite(StepperA1, LOW);
//    break;
//    
//   case 2:
//    digitalWrite(StepperB2, HIGH); 
//    delay(10*time); 
//    digitalWrite(StepperB2, LOW);
//    break;
//    
//   case 3:
//    digitalWrite(StepperA2, HIGH);
//    delay(10*time); 
//    digitalWrite(StepperA2, LOW); 
//    break;
//   
//    case 4:
//    digitalWrite(StepperB1, HIGH);    
//    delay(10*time);                          //A small amount of time here allows for the shaft to move over.
//    digitalWrite(StepperB1, LOW);
//    Button_Count = 0;                       //Set Button_Count back to zero to start over.
//    break;
//   }
 // digitalWrite(Enable_X, LOW);

//FOR DEBUGGING:
Fast();
//Slow_Steps();

}



//This function takes one step at a time but in 4 step groups.
//The status of Button 1 is transmitted through serial port.
void Slow_Steps(){
                 //  Button_Read_1 = digitalRead(Button_1); 
                //  Serial.print(Button_Read_1);
                //delay(50);
               // if (Button_Read_1 == 1 )
   while(digitalRead(Button_1) == 1)
    { 
      digitalWrite(Enable_X, HIGH);
           
      digitalWrite(StepperA1, HIGH); 
      delay(time);
      delay(500);
      digitalWrite(StepperA1, LOW); 
      delay(time);
      digitalWrite(StepperB2, HIGH); 
      delay(time);  
      delay(500); 
      digitalWrite(StepperB2, LOW);
      delay(time);
      digitalWrite(StepperA2, HIGH);
      delay(time); 
      delay(500);
      digitalWrite(StepperA2, LOW); 
      delay(time);
      digitalWrite(StepperB1, HIGH);    
      delay(time);
      delay(500);
      digitalWrite(StepperB1, LOW);
      delay(time);   
           
    }
  
  Button_Read_2 = digitalRead(Button_2); 
  if (Button_Read_2 == 1)
  {
    digitalWrite(StepperB1, HIGH); 
    delay(time);
    delay(500);
    digitalWrite(StepperB1, LOW); 
    delay(time);
    digitalWrite(StepperA2, HIGH); 
    delay(time);  
    delay(500); 
    digitalWrite(StepperA2, LOW);
    delay(time);
    digitalWrite(StepperB2, HIGH);
    delay(time);
    delay(500); 
    digitalWrite(StepperB2, LOW); 
    delay(time);
    digitalWrite(StepperA1, HIGH);    
    delay(time);
    delay(500);
    digitalWrite(StepperA1, LOW);
    delay(time);          
  }

}



//This code moves the steppers at maximum rate.
void Fast() {
  Button_Read_1 = digitalRead(Button_1);
   Serial.print(Button_Read_1);
  
  if (Button_Read_1 == 1)
  {
    digitalWrite(Enable_X, HIGH);
    digitalWrite(Enable_Y, HIGH);
    
    digitalWrite(StepperA1, HIGH); //Forward
    delay(time);
    digitalWrite(StepperA1, LOW); 
    delay(time);
    digitalWrite(StepperB2, HIGH); 
    delay(time);   
    digitalWrite(StepperB2, LOW);
    delay(time);
    digitalWrite(StepperA2, HIGH);
    delay(time); 
    digitalWrite(StepperA2, LOW); 
    delay(time);
    digitalWrite(StepperB1, HIGH);    
    delay(time);
    digitalWrite(StepperB1, LOW);
    delay(time);     

    digitalWrite(Enable_X, LOW);
    digitalWrite(Enable_Y, LOW);
  }
  Button_Read_2 = digitalRead(Button_2); //Reverse
  if (Button_Read_2 == 1)
  {
    digitalWrite(Enable_X, HIGH);
    digitalWrite(Enable_Y, HIGH);
    
    digitalWrite(StepperB1, HIGH); 
    delay(time);
    digitalWrite(StepperB1, LOW); 
    delay(time);
    digitalWrite(StepperA2, HIGH); 
    delay(time);   
    digitalWrite(StepperA2, LOW);
    delay(time);
    digitalWrite(StepperB2, HIGH);
    delay(time); 
    digitalWrite(StepperB2, LOW); 
    delay(time);
    digitalWrite(StepperA1, HIGH);    
    delay(time);
    digitalWrite(StepperA1, LOW);
    delay(time);     

    digitalWrite(Enable_X, LOW);
    digitalWrite(Enable_Y, LOW); 
  }
}







  

