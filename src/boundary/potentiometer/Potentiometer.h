#ifndef __POTENTIOMETER__
#define __POTENTIOMETER__

#include "boundary/Input.h"

class Potentiometer : public Input {
    public:
        Potentiometer(int pin) : Input(pin) {};
        int readValue();
};

#endif