#include <Servo.h>

int sensor = A0;
int LV;
int servoPin = 9;
int dt = 400;
int led = 5;

Servo MyServo;

void setup() {
  Serial.begin(9600);
  MyServo.attach(servoPin);
  pinMode(led, OUTPUT);
}

void loop() {

 
  for (int pos = 0; pos <= 180; pos += 20) {
    MyServo.write(pos);

    LV = analogRead(sensor);
    Serial.println(LV);

    if (LV <= 300) {
      analogWrite(led, 255);   // Dark = fully on
    }
    else if (LV <= 500) {
      analogWrite(led, 100);   // Slightly dim = dim LED
    }
    else {
      analogWrite(led, 0);     // Bright = off
    }

    delay(dt);
  }

  // Sweep 180 → 0
  for (int pos = 180; pos >= 0; pos -= 20) {
    MyServo.write(pos);

    LV = analogRead(sensor);
    Serial.println(LV);

    if (LV <= 300) {
      analogWrite(led, 255);
    }
    else if (LV <= 500) {
      analogWrite(led, 100);
    }
    else {
      analogWrite(led, 0);
    }

    delay(dt);
  }
}