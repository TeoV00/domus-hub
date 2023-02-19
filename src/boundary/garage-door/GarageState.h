#ifndef __GARAGE_STATE__
#define __GARAGE_STATE__

enum GarageState {
    CLOSE,
    OPEN,
    CLOSING,
    OPENING,
    PAUSE,
    REQ_CLOSE, //close request
    REQ_OPEN, //open request
    REQ_PAUSE
};

#endif