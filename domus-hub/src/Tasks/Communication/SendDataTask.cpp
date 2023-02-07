
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
    StaticJsonDocument<192> doc;
    doc["inLight"] = this->homeState->inLight;
    doc["outLight"] = this->homeState->outLight;
    doc["alarmState"] = this->homeState->alarmState;
    doc["heatSysPwr"] = this->homeState->heatSysPwr;
    doc["heatTemp"] = this->homeState->heatTemp;
    doc["garageState"] = this->homeState->garageState;
    doc["btConnected"] = this->homeState->btConnected;
    serializeJson(doc, Serial);
    Serial.println();
};