#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "seu_ssid";
const char* password = "sua_senha";
const String api_url = "sua_api";
const int LED_PIN = 12;


WiFiClient client;
HTTPClient http;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi!");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  
  // Ler o estado do LED da API
  http.begin(client, api_url + "/estado");
  int httpCode = http.GET();
  if (httpCode == HTTP_CODE_OK) {
    String resposta = http.getString();
    if (resposta == "ligado") {
      digitalWrite(LED_PIN, HIGH);
    } else {
      digitalWrite(LED_PIN, LOW);
    }
  }
  http.end();
  
  delay(1000);
}