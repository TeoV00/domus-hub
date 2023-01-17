
#ifndef __RECV_TASK__
#define __RECV_TASK__

#include <HardwareSerial.h>
#include "Task.h"
#include "HomeState.h"

class RecvDataTask: public Task{
    HomeState* homeState;

    public:
        RecvDataTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif