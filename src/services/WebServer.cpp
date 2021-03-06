#include <services/WebServer.h>

ESP8266WebServer server(80);

void WebServer::handleRoot() {
  server.send(200, "text/plain", "hello from esp8266!");
}

void WebServer::handleNotFound() {
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }

  server.send(404, "text/plain", message);
}

void WebServer::handleBlink() {
  int value = digitalRead(LED_BUILTIN);

  String message = value == HIGH ? "Set to low" : "Set to high";
  digitalWrite(LED_BUILTIN, value == HIGH ? LOW : HIGH);

  server.send(200, "text/plain", message);
}

void WebServer::setup() {
  server.on("/", handleRoot);
  server.on("/blink", handleBlink);
  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void WebServer::handleClient() {
  server.handleClient();
}
