/*  SumoBot 1.0
    built to weeeen                                              
    Description:  Reads each sensor every loop. Any instance of   
                  black line it backs up and turns right
*/

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
  
  analogWrite(ena, 150); //This is your motor speed
  analogWrite(enb, 150); //Change these values as needed.  range is 0 - 255
  
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
  
  // all black means all of the sensors are on the line. GO BACK  
  if(digitalRead(lineC)==0 || digitalRead(lineL)==0 || digitalRead(lineR)==0){
    goBack();   
  }else{
    goForward();
  }
 
}

boolean forward()
{
   if(digitalRead(lineC)==0 && digitalRead(lineL)==1 && digitalRead(lineR)==1) 
      return true;
   else 
      return false;     
}

boolean blackLeft()
{
  if(digitalRead(lineL)==0 && digitalRead(lineC)==1 && digitalRead(lineR)==1) 
    return true;
  else
    return false;
}

boolean blackRight()
{ 
    if(digitalRead(lineC)==1 && digitalRead(lineL)==1 && digitalRead(lineR)==0) 
      return true;
    else 
      return false; 
}

boolean blackAll()
{
    if(digitalRead(lineC)==0 || digitalRead(lineL)==0 || digitalRead(lineR)==0) 
      return true;
    else
      return false;
}

////////////////////////////////////////////////////////////////////////////////
void goForward()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);   
  
}

void goBack()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH); 
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(500);
    goRight();
} 

void goLeft()
{
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);   
    delay(250);
}

void goRight()
{
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW); 
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(400);
   
  
}

     

