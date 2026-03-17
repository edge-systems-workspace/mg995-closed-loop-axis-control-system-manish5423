#include <Arduino.h>
#include <Servo.h>
Servo myServo;
#define SERVO_PIN 9
void setup() {
    myServo.attach(SERVO_PIN);
    Serial.begin(9600);
}


void loop()
{
    myServo.write(0);
    delay(1000);
    myServo.write(90);
    delay(1000);
    myServo.write(120);
    delay(1000);
    myServo.write(180);
    delay(1000);



    for(int i = 0; i <= 180; i++) {
        myServo.write(i);
        delay(500);
    }
    for(int i = 180; i >= 0; i--) {
        myServo.write(i);
        delay(500);
    }
}