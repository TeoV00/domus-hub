
#include "Tasks/Communication/SerialCommTask.h"
#include "HomeState.h"
#include "SensorData.h"
#include <ArduinoJson.h>

SerialCommTask::SerialCommTask(HomeState* homeState, SensorData* sensorData) {
    this->homeState = homeState;
    this->sensorData = sensorData;
};

void SerialCommTask::init(int timeoutExec){
    Task::init(timeoutExec);
}

void SerialCommTask::tick() {
    this->sendData();
    this->recvData();
};

void SerialCommTask::sendData() {
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
}

//{"temp": 0,"extLight": 0}
void SerialCommTask::recvData() {
    if (Serial.available() > 0) {
        StaticJsonDocument<96> doc;
        DeserializationError error = deserializeJson(doc, Serial);
       
        if (!error) {
            sensorData->temp = doc["temp"];
            sensorData->extLight = doc["extLight"];
        } else {
            Serial.println("Errore lettura json sensori");
        }
    }
}