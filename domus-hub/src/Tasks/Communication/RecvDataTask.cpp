
#include <HardwareSerial.h>
#include "Tasks/Communication/RecvDataTask.h"
#include "ArduinoJson.h"

RecvDataTask::RecvDataTask(HomeSensorData* sensorData) {
    this->sensorData = sensorData;
    Serial.begin(9600);
};

void RecvDataTask::init(int timeoutExec){
    Task::init(timeoutExec);
};

void RecvDataTask::tick() {
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
};