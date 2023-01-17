#ifndef __UTILITY_JSON__
#define __UTILITY_JSON__

#include "HomeState.h"
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
  "garageState": 0
}

{"inLight":0,"outLight":0,"alarmLight":0,"alarmPwr":0,"moveDetected":0,"heatSysPwr":0,"heatTemp":23,"garageState":0}
*/
void jsonToData(String json, HomeState* homeState);
#endif