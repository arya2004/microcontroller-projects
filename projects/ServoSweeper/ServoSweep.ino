/*************************************************************
  ServoSweep.ino
  Description: Sweeps a servo motor attached to pin 9 from 0 to 180 degrees and back in steps of 1 degree.

  Author: Anonymous

  This example code is in the public domain.
*************************************************************/

#include <Servo.h>

int pos = 0; // Variable to hold the servo position

Servo servo_9; // Create a servo object

void setup() {
  servo_9.attach(9, 500, 2500); // Attach the servo to pin 9 with pulse width limits
}

void loop() {
  // Sweep the servo from 0 to 180 degrees in steps of 1 degree
  for (pos = 0; pos <= 180; pos += 1) {
    // Set the servo position
    servo_9.write(pos);
    // Wait for the servo to reach the position
    delay(5); // Wait for 5 milliseconds
  }

  // Sweep the servo from 180 to 0 degrees in steps of 1 degree
  for (pos = 180; pos >= 0; pos -= 1) {
    // Set the servo position
    servo_9.write(pos);
    // Wait for the servo to reach the position
    delay(5); // Wait for 5 milliseconds
  }
}
