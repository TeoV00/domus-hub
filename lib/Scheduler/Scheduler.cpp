
#include "Scheduler.h"
#include <stdio.h>
#include <Arduino.h>

void Scheduler::init(int basePeriod){
    this->basePeriod = basePeriod;
    taskAddingIdx = 0;
};

void Scheduler::addTask(Task* task){
    if(this->taskAddingIdx < MAX_TASK-1) {
        this->taskList[taskAddingIdx] = task;
        this->taskAddingIdx++;
    }
};

void Scheduler::schedule() {
    delay(this->basePeriod);
    for(int i=0; i< this->taskAddingIdx; i++) {
        if(taskList[i]->checkIfTimeToExec(this->basePeriod) && taskList[i]->isEnabled()){
            taskList[i]->tick();
        }
    }
};