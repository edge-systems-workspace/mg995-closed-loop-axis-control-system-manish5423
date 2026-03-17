/**
 * @file main.cpp
 * @brief Basic MG995 servo motion demo for Arduino.
 * @author Manish Saini
 * @date 2026-03-17
 * @details Attaches an MG995 servo to a digital pin, initializes serial communication,
 *          moves to a few fixed angles, and then performs a slow sweep from 0 to 180
 *          degrees and back to 0 degrees repeatedly.
 */
#include <Arduino.h>
#include <Servo.h>

/** @brief Servo object used to control the MG995 motor. */
Servo myServo;

/** @brief Arduino digital pin connected to the servo signal line. */
#define SERVO_PIN 9

/**
 * @brief Initializes the servo and serial interface.
 * @details Attaches the servo to `SERVO_PIN` and starts serial communication
 *          at 9600 baud for basic monitoring or future debugging.
 */
void setup() {
    myServo.attach(SERVO_PIN);
    Serial.begin(9600);
}

/**
 * @brief Repeatedly commands the servo through preset angles and sweep motion.
 * @details Moves the servo to 0, 90, 120, and 180 degrees with pauses between
 *          each position, then sweeps gradually from 0 to 180 degrees and back.
 */
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