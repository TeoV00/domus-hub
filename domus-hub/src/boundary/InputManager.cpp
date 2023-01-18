
#include "boundary/inputs/Button.h"
#include "boundary/inputs/ButtonImpl.h"
#include "InputManager.h"
#include "PinSetup.h"

InputManager::InputManager() {
    this->alarmBtn = new ButtonImpl(ALARM_BTN_PIN);
    this->heatingBtn = new ButtonImpl(HEATING_BTN_PIN);
}

void InputManager::syncButtons() {
    this->heatBtnPressed = this->heatingBtn->isPressed();
    this->alarmBtnPressed = this->alarmBtn->isPressed();
};

bool InputManager::isHeatingBtnPressed() {
    bool tmpState = this->heatBtnPressed;
    this->heatBtnPressed = false;
    return tmpState;
}

bool InputManager::isAlarmBtnPressed() {
    bool tmpState = this->alarmBtnPressed;
    this->alarmBtnPressed = false;
    return tmpState;
}
