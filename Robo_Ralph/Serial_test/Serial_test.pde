//For testing serial communication.
//It prints the coms that it sees.
//It sends data to the com specified.
//In this case we are sending data to an Arduino to control a servo.



import processing.serial.*; 
Serial port;
void setup(){
println(Serial.list()); 
String portName = Serial.list()[1];//<-----------This is the com it sends data to.
port = new Serial(this, portName, 9600); 
}
void draw(){} 
void keyPressed(){ 
if(key == 'a'){
port.write(0);
}
if(key == 's'){
port.write(90);
}
if(key == 'd'){
port.write(180);
}
}
