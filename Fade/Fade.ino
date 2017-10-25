
void setup() {
  // put your setup code here, to run once:
  pinMode(11,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int brightness = 255; brightness >= 0; brightness -= 5){
    Serial.println(brightness);
    analogWrite(11, brightness);
    delay(30);
  }
  for(int brightness = 0; brightness <= 255; brightness += 5){
    Serial.println(brightness);
    analogWrite(11, brightness);
    delay(30);
  }
}
