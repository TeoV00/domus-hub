#include <Arduino.h>

#include "HomeState.h"
#include "Scheduler.h"
#include "./Tasks/GarageTask.h"
#include "./Tasks/DisplayTask.h"
#include "./Tasks/IndoorLightTask.h"
#include "./Tasks/Communication/SendDataTask.h"
#include "./Tasks/Communication/RecvDataTask.h"

#define SCHED_PERIOD 10

HomeState homeState;
Scheduler sched;
GarageTask* garageTask;
DisplayTask* displayTask;
IndoorLightTask* indoorLightTask;
SendDataTask* sendDataTask;
RecvDataTask* recvDataTask;

void setup() {
    Serial.begin(9600);
    sched.init(SCHED_PERIOD);
    
    garageTask = new GarageTask(&homeState);
    garageTask->init(60);
    sched.addTask(garageTask);

    displayTask = new DisplayTask(&homeState);
    displayTask->init(800);
    sched.addTask(displayTask);
    //displayTask->disable();

    indoorLightTask = new IndoorLightTask(&homeState);
    indoorLightTask->init(300);
    sched.addTask(indoorLightTask);

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