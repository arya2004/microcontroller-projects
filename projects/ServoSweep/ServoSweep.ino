/*************************************************************
  ServoSweep.ino
  Description: Sweeps a servo motor from 0 to 180 degrees and back.

  Author: Anonymous

  This example code is in the public domain.
*************************************************************/

#include <Servo.h>

Servo servo_9;
int pos = 0;

void setup() {
  servo_9.attach(9, 500, 2500); // Attach servo to pin 9 with custom min and max pulse widths
}

void loop() {
  // Sweep the servo from 0 to 180 degrees in steps of 1 degree
  for (pos = 0; pos <= 180; pos += 1) {
    servo_9.write(pos); // Set servo position to 'pos'
    delay(5); // Wait for servo to reach the position
  }
  
  // Sweep the servo from 180 to 0 degrees in steps of 1 degree
  for (pos = 180; pos >= 0; pos -= 1) {
    servo_9.write(pos); // Set servo position to 'pos'
    delay(5); // Wait for servo to reach the position
  }
}
