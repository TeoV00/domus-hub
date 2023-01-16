#ifndef __GARAGE_TASK_H__
#define __GARAGE_TASK_H__

#include "Task.h"
#include "boundary/garage-door/GarageDoor.h"

class GarageTask: public Task{
    GarageState* garageState;
    GarageDoor* garageDoor;

    public:
        GarageTask(GarageState* garageState, GarageDoor* garageDoor);
        void init(int timeoutExec);
        void tick();

};

#endif