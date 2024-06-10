/*************************************************************
  LEDSequence.ino
  Description: Sequentially controls LEDs connected to digital pins.

  Author: Anonymous

  This example code is in the public domain.
*************************************************************/

void setup() {
  // Initialize digital pins for LED control
  pinMode(LED_BUILTIN, OUTPUT);
  for (int pin = 0; pin <= 11; pin++) {
    pinMode(pin, OUTPUT);
  }
}

void loop() {
  // Turn off all LEDs
  for (int pin = 0; pin <= 11; pin++) {
    digitalWrite(pin, LOW);
  }
  
  // First LED sequence
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(9, HIGH);
  delay(2000);

  // Second LED sequence
  digitalWrite(1, HIGH);
  digitalWrite(2, LOW);
  delay(800);

  // Third LED sequence
  digitalWrite(0, HIGH);
  digitalWrite(5, HIGH);
  delay(2000);

  // Fourth LED sequence
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  delay(800);

  // Fifth LED sequence
  digitalWrite(3, HIGH);
  digitalWrite(8, HIGH);
  delay(2000);

  // Sixth LED sequence
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  delay(800);

  // Seventh LED sequence
  digitalWrite(6, HIGH);
  digitalWrite(11, HIGH);
  delay(2000);

  // Eighth LED sequence
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(800);
}
