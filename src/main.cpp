#include <Arduino.h>

#define PUMP_INPUT 14

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PUMP_INPUT, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);

  // toggle pump
  digitalWrite(PUMP_INPUT, LOW);
  delay(1000);
  digitalWrite(PUMP_INPUT, HIGH);
  delay(1000);
}
