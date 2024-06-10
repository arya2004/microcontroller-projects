/*************************************************************
  WiFiStatus.ino
  Description: Connects to a WiFi network and prints the connection status.

  Author: Anonymous

  This example code is in the public domain.
*************************************************************/

#include <WiFi.h>

// Define connection timeout in seconds
#define CONNECTION_TIMEOUT 10

// WiFi credentials
const char* ssid = "";
const char* password = "";

// Function to get WiFi status as a string
String get_wifi_status(int status){
    switch(status){
        case WL_IDLE_STATUS:
            return "WL_IDLE_STATUS";
        case WL_SCAN_COMPLETED:
            return "WL_SCAN_COMPLETED";
        case WL_NO_SSID_AVAIL:
            return "WL_NO_SSID_AVAIL";
        case WL_CONNECT_FAILED:
            return "WL_CONNECT_FAILED";
        case WL_CONNECTION_LOST:
            return "WL_CONNECTION_LOST";
        case WL_CONNECTED:
            return "WL_CONNECTED";
        case WL_DISCONNECTED:
            return "WL_DISCONNECTED";
    }
}

void setup() {
  Serial.begin(115200);
  
  // Connect to WiFi network
  WiFi.begin(ssid, password);
  
  // Wait until connected or timeout reached
  unsigned long start_time = millis();
  while ((WiFi.status() != WL_CONNECTED) && ((millis() - start_time) < CONNECTION_TIMEOUT * 1000)) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  
  // Print connection status
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to the WiFi network");
  } else {
    Serial.println("Failed to connect to WiFi");
  }
}

void loop() {
  // Empty loop as setup handles WiFi connection
}
