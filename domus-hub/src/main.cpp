#include <Arduino.h>

#include "HomeState.h"
#include "InputValues.h"

#include "Scheduler.h"
#include "Tasks/GarageTask.h"
#include "Tasks/DisplayTask.h"
#include "Tasks/LightTask.h"
#include "Tasks/InputTask.h"
#include "Tasks/HeatingSysTask.h"
#include "Tasks/AlarmSysTask.h"
#include "Tasks/Communication/SendDataTask.h"
#include "Tasks/Communication/RecvDataTask.h"

#define SCHED_PERIOD 10

HomeState homeState;

Scheduler sched;

GarageTask* garageTask;
DisplayTask* displayTask;
LightTask* lightTask;
SendDataTask* sendDataTask;
RecvDataTask* recvDataTask;
HeatingSysTask* heatSysTask;
AlarmSysTask* alarmSysTask;

void setup() {
    Serial.begin(9600);
    sched.init(SCHED_PERIOD);

    displayTask = new DisplayTask(&homeState);
    displayTask->init(150);
    sched.addTask(displayTask);

    recvDataTask = new RecvDataTask(&homeState);
    recvDataTask->init(100);
    sched.addTask(recvDataTask);
    recvDataTask->disable();  //WARNING: remove it 
    //TODO: problema!!  I dati li ricevo ma poi vengono sovrascritti dall' input task 
   
    heatSysTask = new HeatingSysTask(&homeState);
    heatSysTask->init(200);
    sched.addTask(heatSysTask);

    alarmSysTask = new AlarmSysTask(&homeState);
    alarmSysTask->init(ALARM_TASK_EXEC_TIMEOUT);
    sched.addTask(alarmSysTask);
    
    garageTask = new GarageTask(&homeState);
    garageTask->init(60);
    sched.addTask(garageTask);
    garageTask->disable(); //WARNING: remove it 

    lightTask = new LightTask(&homeState);
    lightTask->init(300);
    sched.addTask(lightTask);
    lightTask->disable(); //WARNING: remove it 

    sendDataTask = new SendDataTask(&homeState);
    sendDataTask->init(2000);
    sched.addTask(sendDataTask);
    sendDataTask->disable(); //WARNING: remove it 
}

void loop() {
    sched.schedule();
}