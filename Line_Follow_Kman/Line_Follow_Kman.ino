int lineC = 11;
int lineL = 12;
int lineR = 13;
int ena = 9;
int enb = 10;
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 5;

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
  analogWrite(ena, 255); //This is your motor speed
  analogWrite(enb, 255); //Change these values as needed.  range is 0 - 255
  
  Serial.begin(9600);
}

void loop()
{
  Serial.print("LineR: " );
  Serial.println(digitalRead(lineR));
   Serial.print("LineC: " );
  Serial.println(digitalRead(lineC));
   Serial.print("LineL: " );
  Serial.println(digitalRead(lineL));
  
  if(forward()){
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);   
  }
  else if(digitalRead(lineC)==0 && digitalRead(lineL)==0 && digitalRead(lineR)==0){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW); 
  }
  if (right()){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH); 
      }
  else if(digitalRead(lineC)==0 && digitalRead(lineL)==0 && digitalRead(lineR)==0){
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW); 
  }
}

boolean forward()
{
    if(digitalRead(lineC)==0 && digitalRead(lineL)==1 && digitalRead(lineR)==1) 
      return true;
    else 
      return false;     
}

boolean right()
{ 
    if(digitalRead(lineC)==1 && digitalRead(lineL)==1 && digitalRead(lineR)==0) 
      return true;
    else 
      return false; 
}
