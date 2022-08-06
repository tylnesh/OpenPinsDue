#include <Arduino.h>
#include <ArduinoJson.h>
#include "GameStatus.hpp"

#define SIMULATOR

#ifndef SIMULATOR
  #include "IOPins.hpp"
#endif

//const char* msg = "Hello";

GameStatus status;
void simulateThrow(GameStatus &status);

#ifdef SIMULATOR
void setup() {
  
  Serial.begin(9600);
  status.round = 0;
  status.ballsThrown = 0;
  status.score = 0;
  for (int i = 0; i<9; i++) {
    status.pinState[i] = false;
  }
    randomSeed(analogRead(0));
}

void loop() {

  StaticJsonDocument<400> doc;
  // long timestamp = millis();
  // doc["timestamp"] = timestamp;
  doc["round"] = status.round;
  doc["ballsThrown"] = status.ballsThrown;
  doc["score"] = status.score;

  const size_t CAPACITY = JSON_ARRAY_SIZE(9);
  StaticJsonDocument<CAPACITY> pinStateDoc;

  JsonArray pinStateArray = pinStateDoc.to<JsonArray>();
  for (int i = 0; i<9; i++) {
    pinStateArray.add(status.pinState[i]);
  }
  doc["pinState"] = pinStateArray;

  // Send the JSON document over the "link" serial port
  serializeJson(doc, Serial);
  Serial.write((byte)0x0B);
  Serial.write((byte)0x65);

  // Wait
  delay(2000);
  simulateThrow(status);
}


void simulateThrow(GameStatus &status) {
  status.resetPins();
  status.ballsThrown++;
  delay(1000);
  for (int i = 0; i<9; i++) {
    if(random(0,2)) {
      status.pinState[i] = true;
      status.score++;
    }
  }
}
#else
void setup(){

}
void loop(){

}

#endif




