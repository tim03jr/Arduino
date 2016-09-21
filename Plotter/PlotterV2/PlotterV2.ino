/*

INFO:

Lower carriage is the x-axis(254 steps). Upper is the y-axis(380 steps).
Zero point is when carriages are as close to the motors as possible.
The voltage going to the pen motor changes the time needed for equal up/down travel. AT 10 volts down time = 29mS and up time = 27mS. 
The delay after the dot commands also affects the travel of the pen.

Needed:
set motors to a zero point(Top left of image).
Implement a button that zeros carriages.(Polling?)
The back_to_zero function must be taylored to match the size of the image.
Install switch that lets the pen carriage know when to stop.
Create a function that reads the entire incoming processing sketch before printing starts. Might need to copy and paste the binary into arduino sketch and use avr/pgmspace.h to add additional storage.
The new_line function needs to be examined. It seems like it's missing a step here and there.
Create a move(iterations, which enable) function instead of seperate functions for x and Y.


*/

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
 // Serial.begin(9600);                            //Here for de-bugging.
}


void loop(){
 
//  Read ALL the data coming in from processing at once and save to an array.  
    While(serial.available()>0)
    {
    data = Serial.read();
    int array[X_size*Y_size]
    }



  
    data = Serial.read();                 //Read those bytes and store them in the byte data.   
    
    if(data==1){
      dot(); 
      move();                        
    //  X_forward();   
    }
    if(data==0){
      X_forward();
    }
    if(data=='L'){
      back_to_zero();
      new_line();    
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
////////////////////////////////////////NEW FUNCTION
void move(count, enable)
{
   digitalWrite(enable, HIGH);            //Enable the X-axis.
   count++;                               //Add one to button count for switch/case.

   switch(count){
    
   case 1:
    digitalWrite(StepperA1, HIGH); //Forward
    delay(pause);
    digitalWrite(StepperA1, LOW); 
    delay(pause);
    digitalWrite(StepperB2, HIGH); 
    delay(pause);   
    digitalWrite(StepperB2, LOW);   
   break;
        
   case 2:
    digitalWrite(StepperA2, HIGH);
    delay(pause); 
    digitalWrite(StepperA2, LOW); 
    delay(pause);
    digitalWrite(StepperB1, HIGH);    
    delay(pause);
    digitalWrite(StepperB1, LOW);
    count = 0;
   break;
   }
  digitalWrite(enable, LOW);            //Disable the x-axis.
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
   break;
        
   case 2:
    digitalWrite(StepperA2, HIGH);
    delay(pause); 
    digitalWrite(StepperA2, LOW); 
    delay(pause);
    digitalWrite(StepperB1, HIGH);    
    delay(pause);
    digitalWrite(StepperB1, LOW);
    X_Count = 0;
   break;
   }
  digitalWrite(Enable_X, LOW);            //Disable the x-axis.
  }


void dot(){
  digitalWrite(Enable_Pen, HIGH);
  
  digitalWrite(StepperA1, HIGH);//Pen goes down
  delay(100);
  digitalWrite(StepperA1, LOW);

  digitalWrite(StepperA2, HIGH);//Pen comes back up
  delay(58);
  digitalWrite(StepperA2, LOW);
  
  digitalWrite(Enable_Pen, LOW);
  delay(300);//////////////////////////////////////////////////////////////////////////////////////Might not need this.
  }



//The Y-axis(upper carriage) moves down(away from motor) one step.
void new_line(){
  
    digitalWrite(Enable_Y, HIGH);            //Enable the y-axis.

    digitalWrite(StepperA1, HIGH); 
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
    delay(100*pause);///////////////////////////////////////////////////////////////Might not need this
    
   digitalWrite(Enable_Y, LOW);            //Disable the y-axis.
   delay(100);
  }

  
//The X-axis(Lower carriage) moves to zero (near the motor).
//For the x-axis(lower carriage) iteration = 64 for entire sweep. (That's ~254 points of resolution.)
//For the y-axis(upper carriage) iteration = 95. (That's ~380 points of resolution.)
void back_to_zero(){
  
  digitalWrite(Enable_X, HIGH);            //Enable the x-axis.
  
  for(int i=0; i<30; i++)
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







