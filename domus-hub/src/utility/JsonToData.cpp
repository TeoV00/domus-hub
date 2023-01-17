#include "HomeState.h"
#include <stdlib.h>
#include <string.h>
#include  <ArduinoJson.h>

void jsonToData(String json, HomeState* homeState) {
    StaticJsonDocument<192> doc;
    DeserializationError error = deserializeJson(doc, json);

    if (!error) {
        homeState->inLight = doc["inLight"]; // 0
        homeState->outLight = doc["outLight"]; // 0
        homeState->alarmLight = doc["alarmLight"]; // 0
        homeState->alarmPwr = doc["alarmPwr"]; // 0
        homeState->moveDetected = doc["moveDetected"]; // true
        homeState->heatSysPwr = doc["heatSysPwr"]; // 0
        homeState->heatTemp = doc["heatTemp"]; // 20
        homeState->garageState = doc["garageState"]; // 0
    }
}