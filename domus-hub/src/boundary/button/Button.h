#ifndef __BUTTON__
#define __BUTTON__

#include "boundary/inputs/Input.h"

class Button : public Input {
    public: 
        virtual bool isPressed() = 0;
        void readValue();
};

#endif
