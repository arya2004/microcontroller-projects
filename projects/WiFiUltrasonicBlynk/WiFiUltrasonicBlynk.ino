/*
  WiFiUltrasonicBlynk.ino
  Description: This code uses an ESP32 to measure distance with an ultrasonic sensor,
  connect to a WiFi network, and send data to the Blynk cloud server if the distance
  is below a certain threshold.

  Hardware setup:
  - Ultrasonic sensor connected to pins 5 (Trig) and 18 (Echo) of the ESP32.
  - The WiFi credentials and Blynk authentication token need to be defined.

  Blynk setup:
  - BLYNK_TEMPLATE_ID: your Blynk template ID.
  - BLYNK_TEMPLATE_NAME: your Blynk template name.
  - BLYNK_AUTH_TOKEN: your Blynk authentication token.

  Circuit:
  - Ultrasonic sensor Trig pin to ESP32 pin 5
  - Ultrasonic sensor Echo pin to ESP32 pin 18
*/

#include <WiFi.h>

// Blynk credentials and WiFi settings
#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""
const char ssid[] = "";
const char pass[] = "";

// Blynk cloud server settings
const char* host = "blynk.cloud";
unsigned int port = 80;

WiFiClient client;

// Ultrasonic sensor pins
const int trigPin = 5;
const int echoPin = 18;

// Define sound speed in cm/us
#define SOUND_SPEED 0.034

// Variables to store sensor data
long duration;
float distance;

// Function to connect to WiFi
void connectNetwork() {
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected");
}

// Function to send HTTP requests
bool httpRequest(const String& method, const String& url, const String& request, String& response) {
  Serial.print(F("Connecting to "));
  Serial.print(host);
  Serial.print(":");
  Serial.print(port);
  Serial.print("... ");
  if (client.connect(host, port)) {
    Serial.println("OK");
  } else {
    Serial.println("failed");
    return false;
  }

  Serial.print(method); 
  Serial.print(" "); 
  Serial.println(url);

  client.print(method); 
  client.print(" ");
  client.print(url); 
  client.println(F(" HTTP/1.1"));
  client.print(F("Host: ")); 
  client.println(host);
  client.println(F("Connection: close"));
  if (request.length()) {
    client.println(F("Content-Type: application/json"));
    client.print(F("Content-Length: ")); 
    client.println(request.length());
    client.println();
    client.print(request);
  } else {
    client.println();
  }

  int timeout = millis() + 5000;
  while (client.available() == 0) {
    if (timeout - millis() < 0) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return false;
    }
  }

  int contentLength = -1;
  while (client.available()) {
    String line = client.readStringUntil('\n');
    line.trim();
    line.toLowerCase();
    if (line.startsWith("content-length:")) {
      contentLength = line.substring(line.lastIndexOf(':') + 1).toInt();
    } else if (line.length() == 0) {
      break;
    }
  }

  response = "";
  response.reserve(contentLength + 1);
  while (response.length() < contentLength) {
    if (client.available()) {
      char c = client.read();
      response += c;
    } else if (!client.connected()) {
      break;
    }
  }
  client.stop();
  return true;
}

// Setup function runs once at startup
void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  delay(10);
  Serial.println();
  Serial.println();

  connectNetwork();
}

// Main loop function runs repeatedly
void loop() {
  String response;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * SOUND_SPEED / 2;
  Serial.println(distance);
  if (distance < 50) {
    if (httpRequest("GET", String("/external/api/update?token=") + BLYNK_AUTH_TOKEN + "&pin=V0&value=" + distance, "", response)) {
      if (response.length() != 0) {
        Serial.print("WARNING: ");
        Serial.println(response);
      }
    }
    delay(1000);
  }
  delay(50);
}
