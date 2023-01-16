#ifndef __DATA__
#define __DATA__

#include "PowerState.h"
#include "boundary/garage-door/GarageState.h"

struct Data {
    PowerState inLight; //indoor lights
    unsigned char outLight; //outdoor light
    PowerState alarmLight; //alarm light indicator
    PowerState alarmPwr; //alarm system power state
    bool moveDetected; //flag to keep info of any movement detection while alarm is active
    PowerState heatSysPwr; //heating system power
    unsigned char heatTemp; // selected heating system temperature 
    GarageState garageState;
};

#endif