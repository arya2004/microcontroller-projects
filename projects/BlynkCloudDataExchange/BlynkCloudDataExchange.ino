/*************************************************************
  BlynkCloudDataExchange.ino
  Description: This code demonstrates how to exchange data with Blynk Cloud using HTTP requests. It sends data to the cloud and reads it back periodically.

  App dashboard setup:
    Value Display widget on V2

  Blynk platform:
    Downloads, docs, tutorials: https://www.blynk.io
    Sketch generator:           https://examples.blynk.cc
    Blynk community:            https://community.blynk.cc
    Follow us:                  https://www.fb.com/blynkapp
                                https://twitter.com/blynk_app

  This example code is in the public domain.
*************************************************************/

#ifdef ESP32
#  include <WiFi.h>
#else
#  include <ESP8266WiFi.h>
#endif

/* Fill in Blynk Device Info */
#define BLYNK_TEMPLATE_ID "1"
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

// Network settings
const char ssid[] = "";
const char pass[] = "";

// Blynk cloud server
const char* host = "blynk.cloud";
unsigned int port = 80;

WiFiClient client;

// Start the WiFi connection
void connectNetwork()
{
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

// HTTP request function
bool httpRequest(const String& method,
                 const String& url,
                 const String& request,
                 String&       response)
{
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

  Serial.print(method); Serial.print(" "); Serial.println(url);

  client.print(method); client.print(" ");
  client.print(url); client.println(F(" HTTP/1.1"));
  client.print(F("Host: ")); client.println(host);
  client.println(F("Connection: close"));
  if (request.length()) {
    client.println(F("Content-Type: application/json"));
    client.print(F("Content-Length: ")); client.println(request.length());
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

void setup()
{
  Serial.begin(9600);
  delay(10);
  Serial.println();
  Serial.println();

  connectNetwork();
}

void loop() {
  String response;

  unsigned long value = millis();

  Serial.print("Sending value: ");
  Serial.println(value);

  if (httpRequest("GET", String("/external/api/update?token=") + BLYNK_AUTH_TOKEN + "&pin=V0&value=" + value, "", response)) {
    if (response.length() != 0) {
      Serial.print("WARNING: ");
      Serial.println(response);
    }
  }

  delay(3000L); // Wait before sending next request
}
