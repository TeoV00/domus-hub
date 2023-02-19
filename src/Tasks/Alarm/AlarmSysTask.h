#ifndef __ALARM_SYS_TASK__
#define __ALARM_SYS_TASK__

#include "Task.h"
#include "HomeState.h"
#include "boundary/button/Button.h"
#include "boundary/pir/MotionSensor.h"
#include "boundary/light/BlinkLed.h"
#include "AlarmState.h"

#define ALARM_TASK_EXEC_TIMEOUT 200

class AlarmSysTask : public Task {
    private:
        HomeState* homeState;
        MotionSensor* motionSensor;
        Button* alarmBtn;
        BlinkLed* ledIndicator;
        AlarmState state;

    public:
        AlarmSysTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif