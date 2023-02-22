
#ifndef __SERIAL_COMM_TASK__
#define __SERIAL_COMM_TASK__

#include "Task.h"
#include <HardwareSerial.h>
#include "HomeState.h"
#include "SensorData.h"

class SerialCommTask: public Task {
    HomeState* homeState;
    SensorData* sensorData;

    private:
        void sendData();
        void recvData();

    public:
        SerialCommTask(HomeState* homeState, SensorData* sensorData);
        void init(int timeoutExec);
        void tick();
};

#endif