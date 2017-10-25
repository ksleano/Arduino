#include <Servo.h>

/* Sumo 3.0
 Description - Sumobot controlled by bluetooth app
 Functions:
      goForward()   - LeftMotor set to 0
                    - RightMotor set to 180
      goBackwards() - Left Motor set to 180
                    - RightMotor set to 0
                    
*/

char command;

////// Servos //////
Servo leftMotor;
Servo rightMotor;
///////////////////



void setup() {
  Serial.begin(9600);
 
  leftMotor.attach(9);
  rightMotor.attach(10);
}


void loop() {
  if(Serial.available()>0){
    command = Serial.read();
      switch(command){
        case 1:
          Serial.println("up");
          goForward();
          break;
        case 4:
          goBackwards();
          Serial.println("back");
          break;
        case 2:
          Serial.println("left");
          goLeft();
          break;
        case 3:
          Serial.println("right");  
          goRight();
          break;
        default:
          Serial.println("stahp");
          wait();
          break;    
    }
  delay(1); // for stability apparently   
  }
}

////////////////////// Functions //////////////////////



void goForward(){
  leftMotor.write(0);
  rightMotor.write(180);
}

void goBackwards(){
  leftMotor.write(180);
  rightMotor.write(0);
}

void goRight(){
  leftMotor.write(180);
  rightMotor.write(180);
}

void goLeft(){
  leftMotor.write(0);
  rightMotor.write(0);
}

void wait(){
  leftMotor.write(90);
  rightMotor.write(90);
}

////////////////////////////////////////////////////////
