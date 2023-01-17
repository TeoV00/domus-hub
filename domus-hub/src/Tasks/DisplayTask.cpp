#include "HomeState.h"
#include "Tasks/DisplayTask.h"
#include "boundary/display/Display.h"
#include "boundary/display/Lcd.h"
#include "PinSetup.h"

DisplayTask::DisplayTask(HomeState* homeState) {
    Lcd* lcd = new Lcd();
    lcd->initLcd(LCD_ADDR);
    this->display = lcd;
    this->homeState = homeState;
    this->updateDisplay();
}

void DisplayTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}

void DisplayTask::tick() {
    /* 
     * If is detected a movement show alarm message
     */
    if (this->homeState->moveDetected) {
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