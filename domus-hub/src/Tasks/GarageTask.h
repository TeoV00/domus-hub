#ifndef __GARAGE_TASK_H__
#define __GARAGE_TASK_H__

#include "Task.h"
#include "HomeState.h"
#include "boundary/garage-door/GarageDoor.h"

class GarageTask: public Task{
    HomeState* homeState;
    GarageDoor* garageDoor;

    public:
        GarageTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();

};

#endif