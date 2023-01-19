#ifndef __SCHED__
#define __SCHED__

#include "Task.h"

#define MAX_TASK 10

class Scheduler {
    Task* taskList[MAX_TASK];
    int taskAddingIdx;
    int basePeriod;

    public:
    void init(int basePeriod);
    virtual void addTask(Task* task);
    virtual void schedule();
};

#endif