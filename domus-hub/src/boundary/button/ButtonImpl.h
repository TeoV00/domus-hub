#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Arduino.h"
#include "Button.h"
#include "boundary/Input.h"

class ButtonImpl : public Button, public Input {
    private:
        int lastTime;
    public: 
        ButtonImpl(int pin) : Input(pin) {
            pinMode(pin, INPUT_PULLUP);
            this->lastTime = 0;
        };
        bool isPressed();
};

#endif
