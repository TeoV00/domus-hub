
#include "BlinkLed.h"
#include "Led.h"

void BlinkLed::switchOn() {
    this->isBlinkSwitchedOn = true;
    this->timeExpired = 0;
    this->lastTime = 0;
    this->blink();
}
void BlinkLed::switchOff() {
    this->isBlinkSwitchedOn = false;
    Led::switchOff();
    this->isLedOn = false;
}

void BlinkLed::blink() {
    this->timeExpired += this->timeStepUnit;
    if (isBlinkSwitchedOn && this->timeExpired - this->lastTime > ALARM_LED_BLINK_FREQ) {
        this->isLedOn = !this->isLedOn;
        if (this->isLedOn) {
            Led::switchOn();
        } else {
            Led::switchOff();
        }
        this->lastTime = this->timeExpired;
    }
}