#include "HomeState.h"
#include "Tasks/DisplayTask.h"
#include "boundary/display/Display.h"
#include "boundary/display/Lcd.h"
#include "PinSetup.h"

DisplayTask::DisplayTask(HomeState* homeState) {
    this->display = new Lcd(LCD_ADDR);
    this->homeState = homeState;
    this->updateDisplay();
}

void DisplayTask::init(int timeoutExec) {
    Task::init(timeoutExec);
    this->display->showInitMessage();
}

void DisplayTask::tick() {
    /* 
     * If is detected a movement show alarm message
     */
    if (this->homeState->alarmState == AlarmState::RINGING) {
        this->display->showAlarmAlertMsg();
    } else {
        this->updateDisplay();
    }
}

void DisplayTask::updateDisplay() {
    AlarmState alarmState = this->homeState->alarmState;
    PowerState alarmPower = (alarmState == AlarmState::A_ON || alarmState == AlarmState::RINGING)? PowerState::ON : PowerState::OFF;
    this->display->updateAlarmState(alarmPower);
    this->display->updateHeatState(homeState->heatSysPwr);
    this->display->updateHeatTemp(homeState->heatTemp);
}