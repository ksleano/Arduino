////////////////////////////////////////////////////////////
// Bluetooth 
// Version 1.0 - sending strings to determine the state of 
//               the LED. Simple and it works.                              
//                                            
//////////////////////////////////////////////////////////// 

String text;
int led1 = 13;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
}

void loop() {
  if(Serial.available()>0){
    text = Serial.readString();

    if(text == "on"){
      digitalWrite(led1, HIGH);
    }else{
      digitalWrite(led1, LOW);
    }
  }
}
