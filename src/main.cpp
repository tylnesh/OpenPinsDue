#include <Arduino.h>
#include <ArduinoJson.h>
#include "GameStatus.hpp"

#define SIMULATOR

#ifndef SIMULATOR
  #include "IOPins.hpp"
#endif

//const char* msg = "Hello";

byte messageDelimiter[] = {(byte)0x0B, (byte)0x65};
GameStatus status;
void simulateThrow(GameStatus &status);
void sendStatus(GameStatus &status);

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

  delay(1000);
  simulateThrow(status);

//   for (int i = 0; i<9; i++) {
//   Serial.print(status.pinState[i]);
//  }


  sendStatus(status);
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


void sendStatus(GameStatus &status) {
 StaticJsonDocument<500> doc;
 JsonObject message = doc.to<JsonObject>();

 message["command"] = 24;
 JsonObject jsonStatus = message.createNestedObject("status");
 jsonStatus["round"] = status.round;
 jsonStatus["ballsThrown"] = status.ballsThrown;
 jsonStatus["score"] = status.score;
 JsonArray pinStateArray = jsonStatus.createNestedArray("pinState");
 for (int i = 0; i<9; i++) {
  pinStateArray.add(status.pinState[i]);
 }

 serializeJson(message, Serial);
 Serial.write((byte)0x0B);
 Serial.write((byte)0x65);
}
#else
void setup(){

}
void loop(){

}

#endif




