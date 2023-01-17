#include "Data.h"
#include "Tasks/DisplayTask.h"
#include "boundary/display/Display.h"
#include "boundary/display/Lcd.h"
#include "PinSetup.h"

DisplayTask::DisplayTask(Data* data) {
    Lcd* lcd = new Lcd();
    lcd->initLcd(LCD_ADDR);
    this->display = lcd;
    this->data = data;
    this->updateDisplay();
}

void DisplayTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}

void DisplayTask::tick() {
    if (this->data->moveDetected) {
        this->display->showAlarmAlertMsg();
    } else {
        this->updateDisplay();
    }
}

void DisplayTask::updateDisplay() {
    lcd->updateAlarmState(data->alarmPwr);
    lcd->updateHeatState(data->heatSysPwr);
    lcd->updateHeatTemp(data->heatTemp);
}