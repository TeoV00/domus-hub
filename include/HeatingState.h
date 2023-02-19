#ifndef __HEATING_STATE__
#define __HEATING_STATE__

enum HeatingState {
    H_OFF,
    H_ON,
    H_TIMED_ON // heating system is ON just for some time T then goes H_OFF
};

#endif