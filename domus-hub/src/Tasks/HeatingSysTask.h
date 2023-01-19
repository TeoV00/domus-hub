#ifndef __HEATING_SYS_TASK__
#define __HEATING_SYS_TASK__

#include "Task.h"
#include "HomeState.h"
#include "InputValues.h"

class HeatingSysTask : public Task {
    private:
        HomeState* homeState;
        InputValues* inputValues;

    public:
        HeatingSysTask(HomeState* homeState, InputValues* inputValues);
        void init(int timeoutExec);
        void tick();
};

#endif