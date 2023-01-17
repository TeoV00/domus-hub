#include <Arduino.h>

#include "Scheduler.h"
#include "./Tasks/GarageTask.h"
#include "./Tasks/DisplayTask.h"
#include "boundary/garage-door/GarageDoor.h"
#include "./Tasks/IndoorLightTask.h"
#include "HomeState.h"

#define SCHED_PERIOD 10

HomeState homeState;
Scheduler sched;
GarageTask* garageTask;
DisplayTask* displayTask;
IndoorLightTask* indoorLightTask;

void setup() {
    homeState.garageState = GarageState::CLOSE;
    homeState.alarmLight = PowerState::OFF;
    homeState.alarmPwr = PowerState::OFF;
    homeState.heatSysPwr = PowerState::OFF;
    homeState.heatTemp = 20;
    homeState.inLight = PowerState::OFF;
    homeState.outLight = 0;
    homeState.moveDetected = false;
    Serial.begin(9600);
    sched.init(SCHED_PERIOD);
    
    garageTask = new GarageTask(&homeState);
    garageTask->init(100);
    sched.addTask(garageTask);

    displayTask = new DisplayTask(&homeState);
    displayTask->init(500);
    sched.addTask(displayTask);

    indoorLightTask = new IndoorLightTask(&homeState);
    indoorLightTask->init(250);
    sched.addTask(indoorLightTask);
}   

void loop() {
    sched.schedule();
}