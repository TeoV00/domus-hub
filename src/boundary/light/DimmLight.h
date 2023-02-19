#ifndef __LIGHT_DIMM__
#define __LIGHT_DIMM__

#include "Light.h"

class DimmLight : public Light {
    public:
        void switchOn() = 0;
        void switchOff() = 0;
        virtual void setBrightness(unsigned char value) = 0;  
};
#endif

