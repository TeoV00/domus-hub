
#include <HardwareSerial.h>
#include "Tasks/Communication/SendDataTask.h"
#include "HomeState.h"

SendDataTask::SendDataTask(HomeState* homeState) {
    this->homeState = homeState;
};

void SendDataTask::init(int timeoutExec){
  Task::init(timeoutExec);
  Serial.begin(9600);
}

void SendDataTask::tick() {
  Serial.print("{\"inLight\":");
  Serial.print(this->homeState->inLight);
  Serial.print(",\"outLight\":");
  Serial.print(this->homeState->outLight);
  Serial.print(",\"alarmLight\":");
  Serial.print(this->homeState->alarmLight);
  Serial.print(",\"alarmPwr\":");
  Serial.print(this->homeState->alarmPwr);
  Serial.print(",\"moveDetected\":");
  Serial.print(this->homeState->moveDetected);
  Serial.print(",\"heatSysPwr\":");
  Serial.print(this->homeState->heatSysPwr);
  Serial.print(",\"heatTemp\":");
  Serial.print(this->homeState->heatTemp);
  Serial.print(",\"garageState\":");
  Serial.print(this->homeState->garageState);
  Serial.println("}");

};