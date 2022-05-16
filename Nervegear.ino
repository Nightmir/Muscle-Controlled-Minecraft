#include <Servo.h>
Servo clicker;
//sensor value
int x =0;
//sensor pin
int sensor = A0;
//positions for rest and click
int rest = 180;
int clicc = 55;
void setup() {
  //attach servo to pin 9
  clicker.attach(9);
  //sensor pin to input
  pinMode(sensor,INPUT);
  //start the serial port
  Serial.begin(9600);
}

void loop() {
  //make a normalized value of the reading to prevent flickering (making the change in value more smooth)
  x += (analogRead(sensor)-x)/4;
  //if the reading is above the threshold, set the servo to the clicked position
  if(x>85){
    clicker.write(clicc); 
  }
  //otherwise, put it in the rest position
  else{
    clicker.write(rest);
  }
}
