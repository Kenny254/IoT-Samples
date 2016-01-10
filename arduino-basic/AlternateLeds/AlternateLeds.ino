#define greenLed 6
#define redLed 7

void setup(){
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop(){
  lightRed();
  delay(1000);
  lightGreen();
  delay(1000);
}

void lightRed(){
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
}

void lightGreen(){
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
}

