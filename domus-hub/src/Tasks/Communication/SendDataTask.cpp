
//#include <HardwareSerial.h>
#include "Tasks/Communication/SendDataTask.h"
#include "HomeState.h"
#include  <ArduinoJson.h>

SendDataTask::SendDataTask(HomeState* homeState) {
    this->homeState = homeState;
};

void SendDataTask::init(int timeoutExec){
    Task::init(timeoutExec);
}

void SendDataTask::tick() {
    StaticJsonDocument<128> doc;
    doc["inLight"] = this->homeState->inLight;
    doc["outLight"] = this->homeState->outLight;
    doc["alarmState"] = this->homeState->alarmState;
    doc["heatSysPwr"] = this->homeState->heatSysPwr;
    doc["heatTemp"] = this->homeState->heatTemp;
    doc["garageState"] = this->homeState->garageState;
    serializeJson(doc, Serial);
    Serial.println();
};