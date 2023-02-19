#ifndef __DATA__
#define __DATA__

#include "PowerState.h"
#include "AlarmState.h"
#include "boundary/garage-door/GarageState.h"

struct HomeState {
    PowerState inLight = PowerState::OFF; //indoor lights
    unsigned int outLight = 0; //outdoor light
    AlarmState alarmState = AlarmState::A_OFF; //alarm system power state
    PowerState heatSysPwr = PowerState::OFF; //heating system power
    unsigned int heatTemp = 20; // selected heating system temperature 
    GarageState garageState = GarageState::CLOSE;
    unsigned int btConnected = 0;
};

#endif