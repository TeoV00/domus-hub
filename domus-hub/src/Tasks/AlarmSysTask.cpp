#include "Task.h"
#include "HomeState.h"
#include "Tasks/AlarmSysTask.h"
#include "boundary/button/SwitchButtonImpl.h"
#include "boundary/pir/PirSensor.h"
#include "boundary/light/BlinkLed.h"
#include "PinSetup.h"

AlarmSysTask::AlarmSysTask(HomeState* homeState) {
    this->homeState = homeState;
    this->alarmBtn = new SwitchButtonImpl(ALARM_BTN_PIN);
    this->motionSensor = new PirSensor(PIR_PIN);
    this->motionSensor->calibrate();
}

void AlarmSysTask::init(int timeoutExec) {
    Task::init(timeoutExec);
    this->ledIndicator = new BlinkLed(ALARM_LIGHT_PIN,timeoutExec);
    this->ledIndicator->switchOn();
}

void AlarmSysTask::tick() {
    this->homeState->alarmPwr = this->alarmBtn->isSwitchedOn() ? PowerState::ON : PowerState::OFF;
    
    /*
    if (this->homeState->alarmPwr == PowerState::ON && this->motionSensorState) {
        this->homeState->moveDetected = true;
        this->homeState->garageState = GarageState::REQ_CLOSE;
        this->homeState->inLight = PowerState::ON;
        this->homeState->outLight = 255;
        
    }
    */
}
