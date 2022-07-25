#include <Arduino.h>
#include <ArduinoJson.h>

struct GameStatus{
  int round;
  int ballsThrown;
  int score;
  bool pinState[9];


  void resetPins(){
    for (int i = 0; i<9; i++) {
      pinState[i] = false;
    }
  }
};

//const char* msg = "Hello";

GameStatus status;
void simulateThrow(GameStatus &status);


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

  // long timestamp = millis();
  StaticJsonDocument<400> doc;
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
  delay(5000);


  simulateThrow(status);
}


void simulateThrow(GameStatus &status) {
  status.resetPins();
  status.ballsThrown++;
  delay(4000);
  for (int i = 0; i<9; i++) {
    if(random(0,2)) {
      status.pinState[i] = true;
      status.score++;
    }
  }
}




