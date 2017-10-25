////////////////////////////////////////////////////////////
// Line Follow 
// Version 1.3 - Implemented previousCommand: 1 for Right
//                                            2 for Left
//                                            3 for Forward
//////////////////////////////////////////////////////////// 
// these are from your line sensor 
// that are GOING to CONNECT to your arduino
int lineC = 11;
int lineL = 12;
int lineR = 13;

// these are from the H-bridge
int ena = 9;
int enb = 10;
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

//------------------- Previous command--------------------//
// 1 for RIGHT, 2 for LEFT, 3 forward
int previousCommand;

void setup()
{
  pinMode(lineC, INPUT);
  pinMode(lineL, INPUT);
  pinMode(lineR, INPUT);
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(7,INPUT);
  analogWrite(ena, 160); 
  analogWrite(enb, 160); 

  Serial.begin(9600);
}

void loop()
{
  //------------------- Serial Reading -------------------//
  Serial.print("LineL: " );
  Serial.println(digitalRead(lineL));
  Serial.print("LineC: " );
  Serial.println(digitalRead(lineC));
  Serial.print("LineR: " );
  Serial.println(digitalRead(lineR));
  //------------------------------------------------------//
  
  //------------------- Personal Switch ------------------//
  // connect pin 7 to ground to make the car move
  digitalWrite(7, HIGH); 
  digitalWrite(in1,LOW);   
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  //------------------------------------------------------//
  

  while(digitalRead(7)==0){
    //------------------- Previous command--------------------//
    // 1 for RIGHT, 2 for LEFT
    int previousCommand;
    
    if(digitalRead(lineL)== 1 && digitalRead(lineC)== 0 && digitalRead(lineR)== 1){
      Serial.println("IN FORWARD" );

      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      previousCommand = 3;
    }else if((digitalRead(lineL)== 0 && digitalRead(lineC)== 1 && digitalRead(lineR)== 1) || 
             (digitalRead(lineL)== 0 && digitalRead(lineC)== 0 && digitalRead(lineR)== 1)) {
      Serial.println("IN LEFT" );
      
      digitalWrite(in1,LOW);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      previousCommand = 2;
    }else if((digitalRead(lineL)== 1 && digitalRead(lineC)== 1 && digitalRead(lineR)== 0) ||
             (digitalRead(lineL)== 1 && digitalRead(lineC)== 0 && digitalRead(lineR)== 0)) {

      Serial.println("IN RIGHT" );
      
      digitalWrite(in1,HIGH);
      digitalWrite(in2,LOW);
      digitalWrite(in3,LOW);
      digitalWrite(in4,LOW);
      
      previousCommand = 1;
    }else{
      Serial.println("All LIGHT");
      if(previousCommand == 2){
        digitalWrite(in1,LOW);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
      }else if(previousCommand == 1){
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,LOW);
      }else{
        digitalWrite(in1,HIGH);
        digitalWrite(in2,LOW);
        digitalWrite(in3,LOW);
        digitalWrite(in4,HIGH);
      }
    }
  }

}

