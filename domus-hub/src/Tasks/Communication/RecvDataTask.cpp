
#include <HardwareSerial.h>
#include "Tasks/Communication/RecvDataTask.h"
#include "ArduinoJson.h"

RecvDataTask::RecvDataTask(HomeSensorData* sensorData) {
    this->sensorData = sensorData;
};

void RecvDataTask::init(int timeoutExec){
    Task::init(timeoutExec);
};

void RecvDataTask::tick() {
    if (Serial.available() > 0) {
        StaticJsonDocument<48> doc;
        DeserializationError error = deserializeJson(doc, Serial);
        if (!error) {
            sensorData->temp = doc["temp"];
            sensorData->extLight = doc["extLight"];
        }
    }
};