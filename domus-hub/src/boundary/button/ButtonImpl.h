#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

#include "boundary/inputs/Input.h"

class ButtonImpl: public Input {
    private:
        int pin;
        
    public: 
        ButtonImpl(int pin);
        bool isPressed();
};

#endif
