#ifndef __LCD__
#define __LCD__

#include "Display.h"
#include <LiquidCrystal_I2C.h>

class Lcd : public Display {
    private:
        LiquidCrystal_I2C* lcd;
        
    public:
        Lcd(uint8_t addr);
        void updateAlarmState(PowerState state);
        void updateHeatState(PowerState state);
        void updateHeatTemp(unsigned int temp);
        void showAlarmAlertMsg();
        void showInitMessage();
        void clear();
};

#endif