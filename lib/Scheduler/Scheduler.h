#ifndef __SCHED__
#define __SCHED__

#include "Task.h"

#define MAX_TASK 10

class Scheduler {
    Task* taskList[MAX_TASK];
    int taskAddingIdx;
    unsigned int basePeriod;
    unsigned long int prevTime;
    unsigned long int curTime;

    public:
    void init(int basePeriod);
    virtual void addTask(Task* task);
    virtual void schedule();
};

#endif