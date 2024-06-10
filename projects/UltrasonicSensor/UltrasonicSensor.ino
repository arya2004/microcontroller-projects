/*************************************************************
  UltrasonicSensor.ino
  Description: Measures distance using an HC-SR04 ultrasonic sensor with an ESP32.

  Author: Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-hc-sr04-ultrasonic-arduino/

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*************************************************************/

// Pin Definitions
const int trigPin = 5;
const int echoPin = 18;

// Define the speed of sound in cm/uS
#define SOUND_SPEED 0.034

// Variables for distance calculation
long duration;
float distanceCm;

void setup() {
  // Start serial communication
  Serial.begin(115200);
  
  // Set pin modes
  pinMode(trigPin, OUTPUT); // Trig pin as output
  pinMode(echoPin, INPUT);  // Echo pin as input
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin to HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distanceCm = duration * SOUND_SPEED / 2;

  // Convert to inches if needed
  
  // Print the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  // Wait for 1 second before taking the next measurement
  delay(1000);
}
