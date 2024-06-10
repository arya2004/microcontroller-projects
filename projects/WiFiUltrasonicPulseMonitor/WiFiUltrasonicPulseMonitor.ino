/*
  WiFiUltrasonicPulseMonitor.ino
  Description: This code uses an ESP32 to measure distance with an ultrasonic sensor, 
  connect to a WiFi network, and send pulse data to a server and a WhatsApp number 
  using the CallMeBot API. It monitors the distance and sends alerts if the pulse 
  is abnormal.

  Hardware setup:
  - Ultrasonic sensor connected to pins 5 (Trig) and 18 (Echo) of the ESP32.
  - The WiFi credentials, phone number, and API key need to be defined.

  Circuit:
  - Ultrasonic sensor Trig pin to ESP32 pin 5
  - Ultrasonic sensor Echo pin to ESP32 pin 18

  Dependencies:
  - WiFi library for connecting to WiFi
  - HTTPClient library for making HTTP requests
  - UrlEncode library for URL encoding
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

// WiFi credentials
const char* ssid = "";
const char* password = "";

// WhatsApp API credentials
String phoneNumber = "+91xxxxxxxxxx";
String apiKey = "";

// Server endpoint
const char* serverName = "http://<domain-name>/:id/esp32";

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 1000;

// Ultrasonic sensor pins
const int trigPin = 5;
const int echoPin = 18;

// Define sound speed in cm/us
#define SOUND_SPEED 0.034

// Variables to store sensor data
long duration;
float distanceCm;

// Function to send message via WhatsApp using CallMeBot API
void sendMessage(String message) {
  // URL for the API request
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);    
  
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200) {
    Serial.println("Message sent successfully");
  } else {
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

// Setup function runs once at startup
void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input

  // Connect to WiFi network
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(2000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
}

// Main loop function runs repeatedly
void loop() {
  if ((millis() - lastTime) > timerDelay) {
    if (WiFi.status() == WL_CONNECTED) {
      WiFiClient client;
      HTTPClient http;
    
      // Trigger the ultrasonic sensor
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
  
      // Measure the duration of the echo
      duration = pulseIn(echoPin, HIGH);
  
      // Calculate the distance
      distanceCm = (duration * SOUND_SPEED) * 2;

      // Send distance data to the server
      http.begin(client, serverName);
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      String httpRequestData = "id=6446041a2db998bcf9bdd2da&pulse=" + String(distanceCm);           
      int httpResponseCode = http.POST(httpRequestData);
      if (httpResponseCode == 200) {
        Serial.println("okay");
      }
      if (httpResponseCode == 201) {
        Serial.println("tachy");
        sendMessage("Patient's pulse was recorded more than 100");
      }
      if (httpResponseCode == 202) {
        Serial.println("brady");
        sendMessage("Patient's pulse was recorded less than 40");
      }
        
      // Free resources
      http.end();
    } else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
