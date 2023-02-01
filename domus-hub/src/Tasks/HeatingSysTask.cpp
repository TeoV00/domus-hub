#include "Arduino.h"
#include "Task.h"
#include "HomeState.h"
#include "InputValues.h"
#include "Tasks/HeatingSysTask.h"

HeatingSysTask::HeatingSysTask(HomeState* homeState) {
    this->homeState = homeState;
}

void HeatingSysTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}

void HeatingSysTask::tick() {
    /*
    int potValue = this->inputValues->tempHeatSelector;
    this->homeState->heatSysPwr = this->inputValues->btnHeat ? PowerState::ON : PowerState::OFF;
    this->homeState->heatTemp = map(potValue,0, 1024, 15, 26);
    */
}