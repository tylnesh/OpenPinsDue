#include <Arduino.h>
#include <ArduinoJson.h>

struct GameStatus{
  int round;
  int ballsThrown;
  int score;
  bool pinState[9];
};

//const char* msg = "Hello";

GameStatus status;

void setup() {
  Serial.begin(9600);
  status.round = 0;
  status.ballsThrown = 0;
  status.score = 0;
  for (int i = 0; i<9; i++) {
    status.pinState[i] = false;
  }
}

void loop() {
  // Serial.write(msg,sizeof(msg)+1);

    // Values we want to transmit
  long timestamp = millis();

  // // Print the values on the "debug" serial port
  // Serial.print("timestamp = ");
  // Serial.println(timestamp);
  // Serial.print("value = ");
  // Serial.println(value);
  // Serial.println("---");

  // Create the JSON document
  StaticJsonDocument<200> doc;
  doc["timestamp"] = timestamp;
  // JsonObject gameStatusJson;
  // gameStatusJson.
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

  // Wait
  delay(5000);
}
