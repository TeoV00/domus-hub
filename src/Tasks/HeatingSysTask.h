#ifndef __HEATING_SYS_TASK__
#define __HEATING_SYS_TASK__

#include "Task.h"
#include "HomeState.h"
#include "SensorData.h"
#include "HeatingState.h"
#include "boundary/button/Button.h"
#include "boundary/potentiometer/Potentiometer.h"

#define MAX_HEAT_TEMP 19
#define MIN_HEAT_TEMP 8
#define TIMEOUT_HEATING_ON 8000

class HeatingSysTask : public Task {
    private:
        HomeState* homeState;
        SensorData* sensorData;
        Button* heatBtn;
        Potentiometer* tempSelector;
        HeatingState state;
        int timeoutCounter;
        int timeoutStep;

    public:
        HeatingSysTask(HomeState* homeState,SensorData* sensorData);
        void init(int timeoutExec);
        void tick();
};

#endif