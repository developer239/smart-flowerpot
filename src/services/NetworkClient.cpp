#include <ESP8266WiFi.h>
#include <services/NetworkClient.h>

void NetworkClient::begin(const char *ssid, const char *password) {
  WiFi.begin(ssid, password);

  Serial.println("");

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
