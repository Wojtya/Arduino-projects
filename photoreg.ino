#include <Servo.h>
#include <DHT.H> //library for humidity and tempereature sensor
#define DHTTYPE 
int tempin;
//initialise variables
int servoPin = 9;
Servo myServo;
int lightPin = A0;
int lightVal;
int redled = 2;
int greenled = 6;
int mapVal;


void setup() {

  // put your setup code here, to run once:
  myServo.attach(servoPin);
  pinMode(lightPin, INPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  delay(250);
  mapVal = map(lightVal, 0, 1023, 0, 180);
  myServo.write(mapVal);
  if(lightVal > 200){
    digitalWrite(greenled, HIGH);
    delay(100);
    digitalWrite(greenled, LOW);
    delay(100);

  }else if(lightVal < 200 ){
    digitalWrite(redled, HIGH);
    delay(100);
    digitalWrite(redled, LOW);
    delay(100);

  }
  
}