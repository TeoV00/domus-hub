#ifndef __ALARM_STATE__
#define __ALARM_STATE__

enum AlarmState {
    A_OFF,
    A_ON,
    RINGING,
    A_RESET, //bluetooth code request to exit RINGING state
    A_SWITCH_OFF,
    A_SWITCH_ON
};

#endif