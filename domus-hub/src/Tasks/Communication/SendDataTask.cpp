
#include <HardwareSerial.h>
#include "Tasks/Communication/SendDataTask.h"
#include "HomeState.h"

SendDataTask::SendDataTask(HomeState* homeState) {
    this->homeState = homeState;
};

void SendDataTask::init(int timeoutExec){
    Task::init(timeoutExec);
}

void SendDataTask::tick() {
    Serial.print("{\"inLight\":");
    Serial.print(this->homeState->inLight);
    Serial.print(",\"outLight\":");
    Serial.print(this->homeState->outLight);
    Serial.print(",\"alarmState\":");
    Serial.print(this->homeState->alarmState);
    Serial.print(",\"heatSysPwr\":");
    Serial.print(this->homeState->heatSysPwr);
    Serial.print(",\"heatTemp\":");
    Serial.print(this->homeState->heatTemp);
    Serial.print(",\"garageState\":");
    Serial.print(this->homeState->garageState);
    Serial.println("}");
};