#ifndef __SWITCH_BUTTON_IMPL__
#define __SWITCH_BUTTON_IMPL__

#include "Arduino.h"
#include "ButtonImpl.h"
#include "SwitchButton.h"

class SwitchButtonImpl : public SwitchButton, public ButtonImpl {
    private:
        bool isSwitchOn;

    public:
        SwitchButtonImpl(int pin) : ButtonImpl(pin) {
            this->isSwitchOn = false;
        };
        bool isSwitchedOn();
        void forceOff();

};

#endif
