#include <Arduino.h>
#include <ArduinoJson.hpp>

struct GameStatus{
  int round;
  int ballsThrown;
  int score;
  bool pinState[9];
};

  const char* msg = "Hello";


void setup() {
Serial.begin(9600);
}

void loop() {
  Serial.write(msg,sizeof(msg)+1);git