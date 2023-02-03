#include "Arduino.h"
#include "HomeState.h"
#include "PinSetup.h"
#include "Tasks/HeatingSysTask.h"
#include "boundary/button/ButtonImpl.h"
#include "boundary/potentiometer/Potentiometer.h"

HeatingSysTask::HeatingSysTask(HomeState* homeState, HomeSensorData* sensorData) {
    this->homeState = homeState;
    this->sensorData = sensorData;
    this->heatBtn = new ButtonImpl(HEATING_BTN_PIN);
    this->tempSelector = new Potentiometer(HEATING_POT_PIN);
}

void HeatingSysTask::init(int timeoutExec) {
    Task::init(timeoutExec);
    this->state = HeatingState::H_OFF;
    this->timeoutCounter = 0;
    this->timeoutStep = timeoutExec;
}

void HeatingSysTask::tick() {
    int potValue = this->tempSelector->readValue();
    this->homeState->heatTemp = map(potValue,0, 1024, MIN_HEAT_TEMP, MAX_HEAT_TEMP);
    unsigned int tempSens = sensorData->temp;

    if (this->state == H_OFF) {
        if (tempSens < this->homeState->heatTemp) {
            this->state = H_ON;
            this->homeState->heatSysPwr = PowerState::ON;
        } else if (this->heatBtn->isPressed()) {
            this->state = H_TIMED_ON;
            this->homeState->heatSysPwr = PowerState::ON;
            this->timeoutCounter = 0;
        } else {
            this->homeState->heatSysPwr = PowerState::OFF;
        }
    } else if (this->state == H_TIMED_ON) {
        this->timeoutCounter += this->timeoutStep;
        if (this->timeoutCounter >= TIMEOUT_HEATING_ON || this->heatBtn->isPressed()) {
            this->state = H_OFF;
        }
    } else if (this->state == H_ON) {
        if (tempSens >= this->homeState->heatTemp) {
            this->state = H_OFF;
        }
    }
}