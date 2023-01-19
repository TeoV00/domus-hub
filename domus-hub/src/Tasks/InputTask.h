#ifndef __INPUT_TASK_H__
#define __INPUT_TASK_H__

#include "Task.h"
#include "InputValues.h"
#include "boundary/button/Button.h"
#include "boundary/pir/MotionSensor.h"
#include "boundary/potentiometer/Potentiometer.h"

class InputTask : public Task {
    private:
        InputValues* inputValues;
        Button* alarmBtn;
        Button* heatBtn;
        MotionSensor* motionSensor;
        Potentiometer* tempSelector;

    public:
        InputTask(InputValues* inputValues);
        void init(int timeoutExec);
        void tick();
};

#endif