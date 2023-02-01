#ifndef __HEATING_SYS_TASK__
#define __HEATING_SYS_TASK__

#include "Task.h"
#include "HomeState.h"
#include "InputValues.h"

class HeatingSysTask : public Task {
    private:
        HomeState* homeState;

    public:
        HeatingSysTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif