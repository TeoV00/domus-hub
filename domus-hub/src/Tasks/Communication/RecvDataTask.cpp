
#include <HardwareSerial.h>
#include "Tasks/Communication/RecvDataTask.h"
#include "HomeState.h"
#include "utility/JsonToData.cpp"

RecvDataTask::RecvDataTask(HomeState* homeState) {
    this->homeState = homeState;
};

void RecvDataTask::init(int timeoutExec){
    Task::init(timeoutExec);
};

void RecvDataTask::tick() {
    if (Serial.available() > 0) {
        String json = Serial.readStringUntil('\n');
        if (json.length() > 0) {
            jsonToData(json, this->homeState);
        }
    }
};