#include "Data.h"
#include <stdlib.h>
#include <string.h>
#include  <ArduinoJson.h>

/*
{
  "inLight": 0,
  "outLight": 0,
  "alarmLight": 0,
  "alarmPwr": 0,
  "moveDetected": true,
  "heatSysPwr": 0,
  "heatTemp": 20,
  "garageDoor": 0
}
*/
void jsonToData(String json, Data* data) {
    StaticJsonDocument<64> doc;
    DeserializationError error = deserializeJson(doc, json);

    if (!error) {
        data->inLight = doc["inLight"]; // 0
        data->outLight = doc["outLight"]; // 0
        data->alarmLight = doc["alarmLight"]; // 0
        data->alarmPwr = doc["alarmPwr"]; // 0
        data->moveDetected = doc["moveDetected"]; // true
        data->heatSysPwr = doc["heatSysPwr"]; // 0
        data->heatTemp = doc["heatTemp"]; // 20
        data->garageDoor = doc["garageDoor"]; // 0
    }
}