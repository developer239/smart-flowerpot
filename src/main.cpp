#include <Arduino.h>
#include <services/WebServer.h>
#include <services/NetworkClient.h>

void setup() {
  Serial.begin(9600);

  pinMode(LED_BUILTIN, OUTPUT);

  NetworkClient::begin("STRV-GUEST", "strvhere");
  WebServer::setup();
}

void loop() {
  WebServer::handleClient();
  delay(1000);
}
