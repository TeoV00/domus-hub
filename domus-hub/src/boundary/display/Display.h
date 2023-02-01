#ifndef __DISPLAY__
#define __DISPLAY__

#include "PowerState.h"

class Display {
    public:
        virtual void updateAlarmState(PowerState state) = 0;
        virtual void updateHeatState(PowerState state) = 0;
        virtual void updateHeatTemp(unsigned int temp) = 0;
        virtual void showAlarmAlertMsg();
        virtual void showInitMessage() = 0;
};

#endif