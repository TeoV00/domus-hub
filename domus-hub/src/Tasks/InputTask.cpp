
#include "Task.h"
#include "InputTask.h"
#include "InputValues.h"
#include "boundary/button/ButtonImpl.h"
#include "boundary/pir/PirSensor.h"
#include "boundary/potentiometer/Potentiometer.h"
#include "PinSetup.h"

InputTask::InputTask(InputValues* inputValues) {
    this->inputValues = inputValues;
}

void InputTask::init(int timeoutExec) {
    Task::init(timeoutExec);
    this->heatBtn = new ButtonImpl(HEATING_BTN_PIN);
    this->tempSelector = new Potentiometer(HEATING_POT_PIN);
}

void InputTask::tick() {
    /*
    if (this->alarmBtn->isPressed()) {
        this->inputValues->btnAlarm =! this->inputValues->btnAlarm;
    }
    if (this->heatBtn->isPressed()) {
        this->inputValues->btnHeat =! this->inputValues->btnHeat;
    }
    this->inputValues->motionSensor = this->motionSensor->motionDetect();
    this->inputValues->tempHeatSelector = this->tempSelector->readValue();
    */
}