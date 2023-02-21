#ifndef __BT_CTRL_H__
#define __BT_CTRL_H__

#include "HomeState.h"
#include <SoftwareSerial.h>

class BtController {
    private:
        SoftwareSerial* bt;
        HomeState* homeState;
        
        int statePin;
        
    public:
        BtController(HomeState* homeState, int btRXpin, int btTXpin, int btStatepiin);
        void receiveData();
        void sendData();
        bool isConnected();
};

#endif