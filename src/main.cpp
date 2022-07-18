#include <Arduino.h>
#include <ArduinoJson.hpp>

const char* msg = "Hello";

void setup() {
Serial.begin(9600);

}

void loop() {
  Serial.println(msg);
  delay(1000);
}