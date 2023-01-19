#ifndef __DATA__
#define __DATA__

#include "PowerState.h"
#include "boundary/garage-door/GarageState.h"

struct HomeState {
    PowerState inLight = PowerState::OFF; //indoor lights
    unsigned char outLight = 0; //outdoor light
    PowerState alarmLight = PowerState::OFF; //alarm light indicator
    PowerState alarmPwr = PowerState::OFF; //alarm system power state
    bool moveDetected = false; //flag to keep info of any movement detection while alarm is active
    PowerState heatSysPwr = PowerState::OFF; //heating system power
    unsigned int heatTemp = 20; // selected heating system temperature 
    GarageState garageState = GarageState::CLOSE;
};

#endif