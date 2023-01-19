
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
    this->alarmBtn = new ButtonImpl(ALARM_BTN_PIN);
    this->heatBtn = new ButtonImpl(HEATING_BTN_PIN);
    this->tempSelector = new Potentiometer(HEATING_POT_PIN);
    this->motionSensor = new PirSensor(PIR_PIN);
    this->motionSensor->calibrate();
}

void InputTask::tick() {
    this->inputValues->btnAlarm = this->alarmBtn->isPressed();
    this->inputValues->btnHeat = this->heatBtn->isPressed();
    this->inputValues->motionSensor = this->motionSensor->motionDetect();
    this->inputValues->tempHeatSelector = this->tempSelector->readValue();
}