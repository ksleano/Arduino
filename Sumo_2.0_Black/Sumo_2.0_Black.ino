#include <Servo.h>

/* Sumo 2.0
 Description - Sumobot with modified servos for continous rotation
               Can also do line following and works decent as a paper weight
 Functions:
      goForward()   - LeftMotor set to 0
                    - RightMotor set to 180
      goBackwards() - Left Motor set to 180
                    - RightMotor set to 0
                    - then turn
*/



////// Servos //////
Servo leftMotor;
Servo rightMotor;
///////////////////

///// Line Sensor ////
int sLeft = 7;
int sCenter = 6;
int sRight = 5;
//////////////4///////


void setup() {
  Serial.begin(9600);

  // The sensor will give us input
  pinMode(sLeft, INPUT);
  pinMode(sCenter, INPUT);
  
  pinMode(sRight, INPUT);

  // This is where we attach the servos
  leftMotor.attach(10);
  rightMotor.attach(9);
}

// Goes on FOREVER. Or until the battery runs out
void loop() {

  // is it ok to go forward? Go check the sensor
  if(checkSensor()){
    // ok to go forward!
    goForward();
  }else{
    // NOT ok to go forward
    goBackwards();
  }
}

////////////////////// Functions //////////////////////

/* if the sensor is on a black line it gives out a value of '0'
   ;and a zero means OFF; and OFF means theres no light
*/
boolean checkSensor(){
  if((digitalRead(sLeft) == 0  && 
      digitalRead(sCenter) == 0 && 
      digitalRead(sRight) == 0)){
    Serial.println("No white line");
    return true; 
  }
  else{ 
    Serial.println("oh white line. GO BACK NOWWW");
    return false;
  }
}

void goForward(){
  leftMotor.write(0);
  rightMotor.write(180);
}

void goBackwards(){
  leftMotor.write(180);
  rightMotor.write(0);
  delay(1000);
  leftMotor.write(180);
  rightMotor.write(180);
  delay(500);
}

///////////////////////////////////////////////////////
