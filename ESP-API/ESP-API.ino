
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Watson";
const char* password = "jon@2050";
const String api_url = "http://laser-striped-flag.glitch.me";

const int led = 12;
const int botao1 = 10;

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

  pinMode(led, OUTPUT);
  pinMode(botao1, INPUT);
}

void loop() {
  // int botao_estado = digitalRead(botao1);
  // if (botao_estado == HIGH) {
  //   // Enviar requisição para API para ligar o LED
  //   http.begin(client, "https://laser-striped-flag.glitch.me/ligar");
  //   http.POST("");
  //   http.end();
  // } else {
  //   // Enviar requisição para API para desligar o LED
  //   http.begin(client, "https://laser-striped-flag.glitch.me/desligar");
  //   http.POST("");
  //   http.end();
  // }
  
  // Ler o estado do LED da API
  http.begin(client, api_url + "/estado");
  int httpCode = http.GET();
  Serial.println(httpCode);
  if (httpCode == HTTP_CODE_OK) {
    String resposta = http.getString();
    Serial.println(resposta);
    if (resposta == "ligado") {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  }
  http.end();
  
  delay(1000);
}