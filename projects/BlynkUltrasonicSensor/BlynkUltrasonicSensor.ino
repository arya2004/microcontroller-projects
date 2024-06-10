/*
  BlynkUltrasonicSensor.ino
  Description: This code uses an ESP32 to measure distance using an ultrasonic sensor and sends the data to the Blynk platform.
  The distance is measured using the HC-SR04 ultrasonic sensor and the data is sent to a Blynk virtual pin.

  Circuit:
  - HC-SR04 Ultrasonic Sensor connected to ESP32
    - VCC to 5V
    - GND to GND
    - TRIG pin to GPIO 5
    - ECHO pin to GPIO 18

  Dependencies:
  - Blynk library for ESP32
  - WiFi library for ESP32

  Notes:
  - Replace the placeholders for BLYNK_TEMPLATE_ID, BLYNK_TEMPLATE_NAME, BLYNK_AUTH_TOKEN, ssid, and pass with your actual Blynk and WiFi credentials.
*/

#define BLYNK_TEMPLATE_ID "TMPL3Sd-eRMR1"
#define BLYNK_TEMPLATE_NAME "spatialAwareness"
#define BLYNK_AUTH_TOKEN "TcKpRwIXQPXercjLVTEbs5kino2vrJXw"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "";
char pass[] = "";

// Ultrasonic sensor pins
const int trigPin = 5;
const int echoPin = 18;

// Define sound speed in cm/uS
#define SOUND_SPEED 0.034

long duration;
float distanceCm;
BlynkTimer timer;

// Timer event function to send data to Blynk virtual pins
void myTimerEvent() {
  // Send a fixed value to virtual pin V1 (for demonstration)
  Blynk.virtualWrite(V1, 55);
}

// Setup function runs once at startup
void setup() {
  // Start serial communication
  Serial.begin(115200);
  
  // Configure ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass, "blynk.cloud", 80);

  // Set up a timer event that triggers every 500 milliseconds
  timer.setInterval(500L, myTimerEvent);
}

// Main loop function runs repeatedly
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in cm
  distanceCm = duration * SOUND_SPEED / 2;

  // Print the distance in the Serial Monitor
  Serial.print("Distance (cm): ");
  Serial.println(distanceCm);

  // Run Blynk and timer
  Blynk.run();
  timer.run();
}
