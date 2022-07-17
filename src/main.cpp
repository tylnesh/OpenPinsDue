#include <Arduino.h>
#include <ArduinoJson.hpp>

void setup() {
Serial.begin(9600);
}

void loop() {
  const char* msg = "Hello\n";
  Serial.write(msg,sizeof(msg));
  delay(5000);
}