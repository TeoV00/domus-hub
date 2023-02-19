
#ifndef __PRINT_TASK__
#define __PRINT_TASK__

#include "Task.h"
#include <HardwareSerial.h>
#include "HomeState.h"

class SendDataTask: public Task {
    HomeState* homeState;

    public:
        SendDataTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif