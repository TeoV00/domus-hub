#include "HomeState.h"
#include <stdlib.h>
#include <string.h>
#include  <ArduinoJson.h>

void jsonToData(String json, HomeState* homeState) {
    StaticJsonDocument<128> doc;
    DeserializationError error = deserializeJson(doc, json);

    if (!error) {
        homeState->inLight = doc["inLight"]; // 0
        homeState->outLight = doc["outLight"]; // 0
        homeState->alarmState = doc["alarmState"]; // 0
        homeState->heatSysPwr = doc["heatSysPwr"]; // 0
        homeState->heatTemp = doc["heatTemp"]; // 20
        homeState->garageState = doc["garageState"]; // 0
    }
}