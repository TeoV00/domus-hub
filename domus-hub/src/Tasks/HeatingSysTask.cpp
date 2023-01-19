#include "Arduino.h"
#include "Task.h"
#include "HomeState.h"
#include "InputValues.h"
#include "Tasks/HeatingSysTask.h"

HeatingSysTask::HeatingSysTask(HomeState* homeState, InputValues* inputValues) {
    this->homeState = homeState;
    this->inputValues = inputValues;
}
void HeatingSysTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}
void HeatingSysTask::tick() {
    bool switchButton = this->inputValues->btnHeat;
    int potValue = this->inputValues->tempHeatSelector;
    if (!switchButton) {
        this->homeState->heatSysPwr = this->homeState->heatSysPwr == PowerState::OFF ? PowerState::ON : PowerState::OFF;
    }
    this->homeState->heatTemp = map(potValue,0, 1024, 15, 26);
}