#ifndef __HEATING_SYS_TASK__
#define __HEATING_SYS_TASK__

#include "Task.h"
#include "HomeState.h"
#include "HeatingState.h"
#include "boundary/button/Button.h"
#include "boundary/potentiometer/Potentiometer.h"

class HeatingSysTask : public Task {
    private:
        HomeState* homeState;
        Button* heatBtn;
        Potentiometer* tempSelector;
        HeatingState state;
        int timeoutCounter;
        int timeoutStep;

    public:
        HeatingSysTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif