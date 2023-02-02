
#ifndef __RECV_TASK__
#define __RECV_TASK__

#include <HardwareSerial.h>
#include "Task.h"
#include "HomeSensorData.h"

class RecvDataTask: public Task{
    HomeSensorData* sensorData;

    public:
        RecvDataTask(HomeSensorData* sensorData);
        void init(int timeoutExec);
        void tick();
};

#endif