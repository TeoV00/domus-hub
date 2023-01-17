#ifndef __LED_DIMM__
#define __LED_DIMM__

#include "DimmLight.h"
#include "Led.h"

class DimmLed : public Led , public DimmLight { 
    public:
        DimmLed(int pin) : Led(pin) {};
        void switchOn();
        void switchOff();
        void setBrightness(unsigned char value);  
};

#endif
