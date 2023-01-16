#ifndef __GARAGE_STATE__
#define __GARAGE_STATE__

enum GarageState {
    CLOSE,
    OPEN,
    CLOSING,
    OPENING,
    CLOSING_P, //closing in pause
    OPENING_P, //opening in pause
};

#endif