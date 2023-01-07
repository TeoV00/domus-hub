#ifndef __LCD__
#define __LCD__

#include "Display.h"
#include <LiquidCrystal_I2C.h>

class Lcd : public Display {
    private:
        LiquidCrystal_I2C* lcd;
        
    public:
        Lcd();
        void initLcd(uint8_t addr);
        void updateAlarmState(PowerState state);
        void updateHeatState(PowerState state);
        void updateHeatTemp(int temp);
        void clear();
};

#endif