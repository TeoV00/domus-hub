
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
    StaticJsonDocument<96> doc;
    doc["iL"] = this->homeState->inLight;
    doc["oL"] = this->homeState->outLight;
    doc["alarm"] = this->homeState->alarmState;
    doc["hP"] = this->homeState->heatSysPwr;
    doc["hT"] = this->homeState->heatTemp;
    doc["gar"] = this->homeState->garageState;
    doc["bt"] = this->homeState->btConnected;
    serializeJson(doc, Serial);
    Serial.println();
};