

///////////////////////////////////////////////////////////////DO NOT ALTER THIS CODE///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//This code works when the delay in the pocessing sketch(PIXELS) is 500mS. This gives enough time for the Arduino serial buffer not to overflow.
//
//INFO:
//I think it's up to processing to choose the correct port(The one Arduino is on). 
//Lower carriage is the x-axis(254 steps). Upper is the y-axis(380 steps).
//Both carriages must be zero'd before trying to print.
//Zero point is when carriages are as close to the motors as possible.
//The voltage going to the pen motor changes the time needed for equal up/down travel. AT 10 volts down time = 29mS and up time = 27mS. 
//The delay after the dot commands also affects the travel of the pen.

//Needed:
//set motors to a zero point(Top left of image).
//Implement a button that zeros carriages.(Polling?)
//The back_to_zero function must be taylored to match the size of the image.

#define StepperA1 2                                 
#define StepperA2 3 
#define StepperB1 4 
#define StepperB2 5 
#define Enable_X 7
#define Enable_Y 6
#define Enable_Pen 8
#define Button_1 10
#define Button_2 11
#define pause 1   
#define time 1                            
byte data;
byte Button_Read_1;
byte Button_Read_2;
int X_Count = 0;
int Y_Count = 0;

void setup() { 
  pinMode(StepperA1, OUTPUT);
  pinMode(StepperA2, OUTPUT);
  pinMode(StepperB1, OUTPUT);
  pinMode(StepperB2, OUTPUT);
  pinMode(Enable_X,  OUTPUT);
  pinMode(Enable_Y,  OUTPUT);
  pinMode(Enable_Pen, OUTPUT);
  pinMode(Button_1, INPUT);
  pinMode(Button_2, INPUT);
  Serial.begin(9600);                            //Here for de-bugging.
}




//This loop will take pixel information from the serial port(processing) and adjust the motors accordingly. 
void loop(){
 
  while(Serial.available()>0){            //While there are bytes of data in the serial buffer.
    data = Serial.read();                 //Read those bytes and store them in the byte data.   
    
    if(data==1){
     // delay(100);
      dot(); 
    //  delay(100),                         
      X_forward();
     // delay(100);      
    }
    if(data==0){
     // delay(100);
      X_forward();
    //  delay(100);  
    }
    if(data=='L'){
     // delay(100);
      back_to_zero();
    //  delay(100);
      new_line();
    //  delay(100);     
    }
  } 
  
  
 
//
//byte Ans_1 = digitalRead(Button_1);    ///////////This is just for debugging using a button.
//if(Ans_1 == 1){
//  //X_forward();
//  //to_end();
//  dot();
//  delay(100);
//  }
//byte Ans_2 = digitalRead(Button_2);  
//if(Ans_2 == 1){
//  //new_line();
// // back_to_zero();
//  delay(500);
//  }  

//Fast();

}

void X_forward() {   
  
   digitalWrite(Enable_X, HIGH);            //Enable the X-axis.
   X_Count++;                               //Add one to button count for switch/case.

   switch(X_Count){
    
    case 1:
    digitalWrite(StepperA1, HIGH); //Forward
    delay(pause);
    digitalWrite(StepperA1, LOW); 
    delay(pause);
    digitalWrite(StepperB2, HIGH); 
    delay(pause);   
    digitalWrite(StepperB2, LOW);
   // delay(100*pause);
    
    break;
        
   case 2:
   digitalWrite(StepperA2, HIGH);
    delay(pause); 
    digitalWrite(StepperA2, LOW); 
    delay(pause);
    digitalWrite(StepperB1, HIGH);    
    delay(pause);
    digitalWrite(StepperB1, LOW);
   // delay(100*pause); 
    X_Count = 0;
   break;
   }
  digitalWrite(Enable_X, LOW);            //Disable the x-axis.
  }


//make a dot/activate laser for a set amount of time.
//Only using one side of H-bridge.
void dot(){
  digitalWrite(Enable_Pen, HIGH);
 // delay(10);//might not need this.
  digitalWrite(StepperA1, HIGH);//Pen goes down
  delay(100);
  digitalWrite(StepperA1, LOW);
  //delay(10);
  digitalWrite(StepperA2, HIGH);//Pen comes back up
  delay(58);
  digitalWrite(StepperA2, LOW);
  digitalWrite(Enable_Pen, LOW);
  delay(300);
  }



//The Y-axis(upper carriage) moves down(away from motor) one step.
void new_line(){
  
   digitalWrite(Enable_Y, HIGH);            //Enable the y-axis.

    digitalWrite(StepperA1, HIGH); //Forward
    delay(pause);
    digitalWrite(StepperA1, LOW); 
    delay(pause);
    digitalWrite(StepperB2, HIGH); 
    delay(pause);   
    digitalWrite(StepperB2, LOW);
    delay(pause);
    digitalWrite(StepperA2, HIGH);
    delay(pause); 
    digitalWrite(StepperA2, LOW); 
    delay(pause);
    digitalWrite(StepperB1, HIGH);    
    delay(pause);
    digitalWrite(StepperB1, LOW);
    delay(100*pause); 
    
   digitalWrite(Enable_Y, LOW);            //Disable the y-axis.
   delay(100);
  }

  
//The X-axis(Lower carriage) moves to zero (near the motor).
//For the x-axis(lower carriage) iteration = 64 for entire sweep. (That's ~254 points of resolution.)
//For the y-axis(upper carriage) iteration = 95. (That's ~380 points of resolution.)
//Should add a button that sends both carriages back to zero.
void back_to_zero(){
  
  digitalWrite(Enable_X, HIGH);            //Enable the x-axis.
  
  for(int i=0; i<30; i++)//4 steps per iteration 15 times = the horizontal resolution of the image(60).
  {
    digitalWrite(StepperB1, HIGH); 
    delay(pause); 
    digitalWrite(StepperB1, LOW); 
    delay(pause); 
    digitalWrite(StepperA2, HIGH); 
    delay(pause);    
    digitalWrite(StepperA2, LOW);
    delay(pause); 
    digitalWrite(StepperB2, HIGH);
    delay(pause); 
    digitalWrite(StepperB2, LOW); 
    delay(pause); 
    digitalWrite(StepperA1, HIGH);    
    delay(pause); 
    digitalWrite(StepperA1, LOW);
    delay(pause); 
  }
  digitalWrite(Enable_X, LOW);            //Disable the x-axis.
  delay(100);
  }

















//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////For debuging.

//For the x-axis(lower carriage) iteration = 64.
//For the y-axis(upper carriage) iteration = 95.

//For now it only controls the lower(x) carriage.
//Forward is away from the motor.
void to_end(){
  
  digitalWrite(Enable_X, HIGH);            //Enable the x-axis.
  digitalWrite(Enable_Y, HIGH);
  
  for(int i=0; i<64; i++){
    digitalWrite(StepperA1, HIGH); //Forward
    delay(pause);
    digitalWrite(StepperA1, LOW); 
    delay(pause);
    digitalWrite(StepperB2, HIGH); 
    delay(pause);   
    digitalWrite(StepperB2, LOW);
    delay(pause);
    digitalWrite(StepperA2, HIGH);
    delay(pause); 
    digitalWrite(StepperA2, LOW); 
    delay(pause);
    digitalWrite(StepperB1, HIGH);    
    delay(pause);
    digitalWrite(StepperB1, LOW);
    delay(pause);   
  }
  digitalWrite(Enable_X, LOW);            //Disable the x-axis.
  digitalWrite(Enable_Y, LOW);
}

//This code moves the steppers at maximum rate.
void Fast() {
  Button_Read_1 = digitalRead(Button_1);
   Serial.print(Button_Read_1);
  
  if (Button_Read_1 == 1)
  {
    digitalWrite(Enable_X, HIGH);
   // digitalWrite(Enable_Y, HIGH);
    
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
   // digitalWrite(Enable_Y, HIGH);
    
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







