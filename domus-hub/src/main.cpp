#include <Arduino.h>

#include "HomeState.h"
#include "Scheduler.h"
#include "./Tasks/GarageTask.h"
#include "./Tasks/DisplayTask.h"
#include "./Tasks/LightTask.h"
#include "./Tasks/Communication/SendDataTask.h"
#include "./Tasks/Communication/RecvDataTask.h"

#define SCHED_PERIOD 10

HomeState homeState;

Scheduler sched;
GarageTask* garageTask;
DisplayTask* displayTask;
LightTask* lightTask;
SendDataTask* sendDataTask;
RecvDataTask* recvDataTask;

void setup() {

    sched.init(SCHED_PERIOD);
    
    garageTask = new GarageTask(&homeState);
    garageTask->init(60);
    sched.addTask(garageTask);

    displayTask = new DisplayTask(&homeState);
    displayTask->init(800);
    sched.addTask(displayTask);

    lightTask = new LightTask(&homeState);
    lightTask->init(300);
    sched.addTask(lightTask);

    sendDataTask = new SendDataTask(&homeState);
    sendDataTask->init(1500);
    sched.addTask(sendDataTask);

    recvDataTask = new RecvDataTask(&homeState);
    recvDataTask->init(30);
    sched.addTask(recvDataTask);

}   

void loop() {
    sched.schedule();
}