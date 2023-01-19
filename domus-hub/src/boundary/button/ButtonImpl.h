#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "Button.h"
#include "boundary/Input.h"

class ButtonImpl : public Button, public Input {

    public: 
        ButtonImpl(int pin) : Input(pin) {};
        bool isPressed();
};

#endif
