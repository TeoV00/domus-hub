#include "Task.h"
#include "HomeState.h"
#include "AlarmSysTask.h"
#include "boundary/button/SwitchButtonImpl.h"
#include "boundary/pir/PirSensor.h"
#include "boundary/light/BlinkLed.h"
#include "PinSetup.h"
#include "AlarmState.h"

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
    this->state = AlarmState::A_OFF;
}

void AlarmSysTask::tick() {
    bool btnStateOn = this->alarmBtn->isSwitchedOn();

    if (this->state == AlarmState::A_OFF) {
        this->ledIndicator->switchOff();
        if (btnStateOn) {
            this->state = AlarmState::A_ON;
        }
    } else if (this->state == AlarmState::A_ON) {
        this->homeState->alarmState = AlarmState::A_ON;
        if (this->motionSensor->motionDetect()) {
            this->state = AlarmState::RINGING;
            this->ledIndicator->switchOn();
        } else if (!btnStateOn) {
            this->state = AlarmState::A_OFF;
        }
    } else if (this->state == RINGING) {
        this->ledIndicator->blink();
        this->homeState->inLight = PowerState::ON;
        this->homeState->outLight = 255;
        this->homeState->garageState = GarageState::REQ_CLOSE;
        if (this->homeState->alarmState == A_RESET && this->homeState->btConnected) {
            this->state = AlarmState::A_OFF;
            this->alarmBtn->forceOff();
            this->homeState->inLight = PowerState::OFF;
        }
    }
    
    this->homeState->alarmState = this->state;
}
