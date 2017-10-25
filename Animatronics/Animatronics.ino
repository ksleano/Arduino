#include <Servo.h>

/*  Animatronics
 *    Description: Servo controlled by an android app. 2 Modes
 *                 available 1 pending 
 */

float command;

////// Servo //////
Servo servo;
///////////////////

void setup() {
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  if(Serial.available()>0){
    command = Serial.read();
    Serial.println(command);
    servo.write(command);  
  }

}
