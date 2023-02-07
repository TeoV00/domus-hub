
#ifndef __BT_RECV_TASK__
#define __BT_RECV_TASK__

#include "Task.h"
#include "HomeState.h"
#include "Communication/Bluetooth/BTController.h"

class BluetoothTask: public Task{
    HomeState* homeState;
    BtController* btCtrl;

    public:
        BluetoothTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif