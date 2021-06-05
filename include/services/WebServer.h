#ifndef SMART_FLOWERPOT_WEBSERVER_H
#define SMART_FLOWERPOT_WEBSERVER_H

#include <ESP8266WebServer.h>

class WebServer {
public:
  static void setup();
  static void handleClient();
private:
  static void handleBlink();
  static void handleRoot();
  static void handleNotFound();
};

#endif //SMART_FLOWERPOT_WEBSERVER_H
