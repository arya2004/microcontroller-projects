/*
  BlynkWiFiControl.ino
  Description: This code uses an ESP32 to connect to a WiFi network and interface with the Blynk platform. 
  It sends periodic updates to virtual pins V0 and V1 on the Blynk server.

  Circuit:
  - ESP32 board

  Dependencies:
  - Blynk library for ESP32
  - WiFi library for ESP32

  Notes:
  - Replace the placeholders for BLYNK_TEMPLATE_ID, BLYNK_TEMPLATE_NAME, and BLYNK_AUTH_TOKEN with your actual Blynk credentials.
  - Replace the placeholders for ssid and pass with your actual WiFi credentials.
*/

// Uncomment and fill in your Blynk credentials
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"
//#define BLYNK_AUTH_TOKEN            "YourAuthToken"
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#include <SPI.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// WiFi credentials
char ssid[] = "";
char pass[] = "";

// Blynk timer instance
BlynkTimer timer;

// Timer event function to send data to Blynk virtual pins
void myTimerEvent() {
  // Send values to virtual pins V1 and V0
  Blynk.virtualWrite(V1, 56);
  Blynk.virtualWrite(V0, 44);
}

// Setup function runs once at startup
void setup() {
  // Debug console
  Serial.begin(115200);

  // Initialize Blynk
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Setup a timer event that triggers every second
  timer.setInterval(1000L, myTimerEvent);
}

// Main loop function runs repeatedly
void loop() {
  // Run Blynk
  Blynk.run();

  // Run timer
  timer.run();
}
