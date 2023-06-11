/* 
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp32-send-messages-whatsapp/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <WiFi.h>    
#include <HTTPClient.h>
#include <UrlEncode.h>

const char* ssid = "";
const char* password = "";

// +international_country_code + phone number

String phoneNumber = "+91xxxxxxxxxx";
String apiKey = "";

void sendMessage(String message){

  // Data to send with HTTP POST
  
  String url1 = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);

  String url = "https://api.callmebot.com/whatsapp.php?phone="+phoneNumber+"&text=This+is+a+test&apikey="+ apikey;    
  HTTPClient http;
  http.begin(url);

  // Specify content-type header
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  // Send HTTP POST request
  int httpResponseCode = http.POST(url);
  if (httpResponseCode == 200){
    Serial.print("Message sent successfully");
  }
  else{
    Serial.println("Error sending the message");
    Serial.print("HTTP response code: ");
    Serial.println(httpResponseCode);
  }

  // Free resources
  http.end();
}

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  // Send Message to WhatsAPP
  String dmail_subject = "Subject: Reminder to use same collection for patient and doctor data in MongoDB"; 

 sendMessage(dmail_subject);
  
  
}

void loop() {
  
}