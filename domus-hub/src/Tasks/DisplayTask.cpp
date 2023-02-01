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
    if (this->homeState->moveDetected && this->homeState->alarmPwr == PowerState::ON) {
        this->display->showAlarmAlertMsg();
    } else {
        this->updateDisplay();
    }
}

void DisplayTask::updateDisplay() {
    this->display->updateAlarmState(homeState->alarmPwr);
    this->display->updateHeatState(homeState->heatSysPwr);
    this->display->updateHeatTemp(homeState->heatTemp);
}