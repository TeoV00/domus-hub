#include <Arduino.h>

#include "HomeState.h"
#include "HomeSensorData.h"

#include "Scheduler.h"
#include "Tasks/GarageTask.h"
#include "Tasks/DisplayTask.h"
#include "Tasks/LightTask.h"
#include "Tasks/HeatingSysTask.h"
#include "Tasks/Alarm/AlarmSysTask.h"
#include "Tasks/Communication/SendDataTask.h"
#include "Tasks/Communication/RecvDataTask.h"
#include "Tasks/BluetoothTask.h"

#define SCHED_PERIOD 10

HomeState homeState;
HomeSensorData sensorData;
Scheduler sched;

GarageTask* garageTask;
DisplayTask* displayTask;
LightTask* lightTask;
SendDataTask* sendDataTask;
RecvDataTask* recvDataTask;
HeatingSysTask* heatSysTask;
AlarmSysTask* alarmSysTask;
BluetoothTask* bluetoothTask;

void setup() {
    Serial.begin(9600);
    
    sched.init(SCHED_PERIOD);
    
    displayTask = new DisplayTask(&homeState);
    displayTask->init(150);
    sched.addTask(displayTask);
   
    heatSysTask = new HeatingSysTask(&homeState, &sensorData);
    heatSysTask->init(200);
    sched.addTask(heatSysTask);

    alarmSysTask = new AlarmSysTask(&homeState);
    alarmSysTask->init(ALARM_TASK_EXEC_TIMEOUT);
    sched.addTask(alarmSysTask);
    
    garageTask = new GarageTask(&homeState);
    garageTask->init(60);
    sched.addTask(garageTask);

    lightTask = new LightTask(&homeState, &sensorData);
    lightTask->init(300);
    sched.addTask(lightTask); 

    recvDataTask = new RecvDataTask(&sensorData);
    recvDataTask->init(100);
    sched.addTask(recvDataTask);

    sendDataTask = new SendDataTask(&homeState);
    sendDataTask->init(2000);
    sched.addTask(sendDataTask);

    bluetoothTask = new BluetoothTask(&homeState);
    bluetoothTask->init(200);
    sched.addTask(bluetoothTask);

}

void loop() {
    sched.schedule();
}