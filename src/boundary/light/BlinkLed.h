#ifndef __LED_BLINK__
#define __LED_BLINK__

#include "DimmLight.h"
#include "Led.h"

#define ALARM_LED_BLINK_FREQ 400

class BlinkLed : public Led {
    private:
        int timeExpired;
        int lastTime;
        int timeStepUnit;
        bool isBlinkSwitchedOn = false;
        bool isLedOn = false;

    public:
        BlinkLed(int pin, int timeStepUnit) : Led(pin) {
            this->timeStepUnit = timeStepUnit;
            this->isBlinkSwitchedOn = false;
            this->isLedOn = false;
        };
        void switchOn();
        void switchOff();
        void blink();
};

#endif
