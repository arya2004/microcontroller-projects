

#include <WiFi.h>
#include <HTTPClient.h>
#include <UrlEncode.h>

const char* ssid = "";
const char* password = "";
String phoneNumber = "+91xxxxxxxxxx";
String apiKey = "";

const char* serverName = "http://192.168.158.129:3000/:id/esp32";

unsigned long lastTime = 0;
unsigned long timerDelay = 1000;


void sendMessage(String message){

  // Data to send with HTTP POST
  String url = "https://api.callmebot.com/whatsapp.php?phone=" + phoneNumber + "&apikey=" + apiKey + "&text=" + urlEncode(message);    
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
    delay(2000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  String dmail_subject = "Subject: Reminder to use same collection for patient and doctor data in MongoDB"; 

  String dmail_body = "Dear Past Me, \n Just wanted to remind you to use the same collection for patient and doctor data in MongoDB. This will make it easier to query both types of data together.\nHope this helps!\nBest regards,\nYour future self";
  sendMessage(dmail_subject);
  sendMessage(dmail_body);
  
}

void loop() {
  if ((millis() - lastTime) > timerDelay) {
   
    if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;
    

      http.begin(client, serverName);

     http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      String httpRequestData = "id=6446041a2db998bcf9bdd2da&pulse="+ String(50 + (rand() % 10)- (rand() % 10));           

      int httpResponseCode = http.POST(httpRequestData);
      if(httpResponseCode == 200){
        Serial.println("okay");
      }
            if(httpResponseCode == 201){
        Serial.println("tachy");
      }
            if(httpResponseCode == 202){
        Serial.println("brady");
      }
        
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}
