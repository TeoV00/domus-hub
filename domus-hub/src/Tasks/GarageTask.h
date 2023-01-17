#ifndef __GARAGE_TASK_H__
#define __GARAGE_TASK_H__

#include "Task.h"
#include "Data.h"
#include "boundary/garage-door/GarageDoor.h"

class GarageTask: public Task{
    Data* data;
    GarageDoor* garageDoor;

    public:
        GarageTask(Data* data);
        void init(int timeoutExec);
        void tick();

};

#endif