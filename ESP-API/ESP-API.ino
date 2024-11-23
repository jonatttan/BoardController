#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>
#include "Conf.h"

const char* ssid = SSID;
const char* password = PWD;
const String api_url = API;

const int LED_PIN = 12;

WiFiClient client;
HTTPClient http;

void configureNetwork() {
  WiFi.mode(WIFI_STA);

  IPAddress ip(192, 168, 2, 140);
  IPAddress gateway(192, 168, 2, 1);
  IPAddress subnet(255, 255, 255, 0);
  IPAddress dns(192, 168, 2, 1);
  WiFi.config(ip, dns, gateway, subnet);

  WiFi.begin(ssid, password);
  Serial.println("");
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(9600);
  configureNetwork();

  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // Read LED state from API
  http.begin(client, api_url + "/state");
  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == HTTP_CODE_OK) {
    String response = http.getString();
    Serial.println(response);

    DynamicJsonDocument jsonDoc(2048);
    DeserializationError error = deserializeJson(jsonDoc, response);

    if (!error) {
      bool led_state = jsonDoc["led1"];
      Serial.print("Led1: ");
      Serial.println(led_state);
      digitalWrite(LED_PIN, led_state);
    } else {
      Serial.println("Deserialization error: ");
      Serial.println(error.c_str());
    }

  }
  http.end();
  
  delay(1000);
}