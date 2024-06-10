/*************************************************************
  ServoMoodIndicator.ino
  Description: This sketch controls a servo motor using a potentiometer to indicate mood or position.

  Parts required:
  - Servo motor
  - 10 kilohm potentiometer
  - Two 100 uF electrolytic capacitors

  Created: 13 Sep 2012
  Author: Scott Fitzgerald
  Source: https://store.arduino.cc/genuino-starter-kit

  This example code is in the public domain.
*************************************************************/

#include <Servo.h>  // Include the Servo library

Servo myServo;     // Create a servo object

int const potPin = A0;  // Analog pin used to connect the potentiometer
int potVal;             // Variable to read the value from the analog pin
int angle;              // Variable to hold the angle for the servo motor

void setup() {
  myServo.attach(9);   // Attach the servo on pin 9 to the servo object
  Serial.begin(9600);  // Open a serial connection to your computer
}

void loop() {
  potVal = analogRead(potPin);  // Read the value of the potentiometer
  // Print out the value to the Serial Monitor
  Serial.print("potVal: ");
  Serial.print(potVal);

  // Scale the numbers from the pot
  angle = map(potVal, 0, 1023, 0, 179);

  // Print out the angle for the servo motor
  Serial.print(", angle: ");
  Serial.println(angle);

  // Set the servo position
  myServo.write(angle);

  // Wait for the servo to get there
  delay(15);
}
