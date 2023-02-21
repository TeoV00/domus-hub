#ifndef __GARAGE_TASK_H__
#define __GARAGE_TASK_H__

#include "Task.h"
#include "HomeState.h"
#include "boundary/garage-door/GarageDoor.h"

class GarageTask: public Task{
    private:
        GarageState* garageState;
        GarageDoor* garageDoor;
        GarageState getGarageState();

    public:
        GarageTask(GarageState* garageState);
        void init(int timeoutExec);
        void tick();

};

#endif