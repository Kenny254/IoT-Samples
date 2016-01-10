#define greenLed 6
#define redLed 7
#define motionSensor 8
#define rpi 9

void setup(){
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(motionSensor, INPUT);
  pinMode(rpi, OUTPUT);
}

void loop(){
  delay(500);
  if(digitalRead(motionSensor) == HIGH){
    lightRed();
    digitalWrite(rpi, HIGH);
  }else{
    lightGreen();
    digitalWrite(rpi, LOW);
  }
  
}

void lightRed(){
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
}

void lightGreen(){
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
}

