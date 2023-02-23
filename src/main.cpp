#include <Arduino.h>

#include "HomeState.h"
#include "SensorData.h"

#include "Scheduler.h"
#include "Tasks/GarageTask.h"
#include "Tasks/DisplayTask.h"
#include "Tasks/LightTask.h"
#include "Tasks/HeatingSysTask.h"
#include "Tasks/Alarm/AlarmSysTask.h"
#include "Tasks/Communication/SerialCommTask.h"
#include "Tasks/BluetoothTask.h"

#define SCHED_PERIOD 20

HomeState homeState;
SensorData sensorData;
Scheduler sched;

GarageTask* garageTask;
DisplayTask* displayTask;
LightTask* lightTask;
HeatingSysTask* heatSysTask;
AlarmSysTask* alarmSysTask;
BluetoothTask* bluetoothTask;
SerialCommTask* serialCommTask;

void setup() {
    Serial.begin(9600);
    
    sched.init(SCHED_PERIOD);

    displayTask = new DisplayTask(&homeState);
    displayTask->init(800);
    sched.addTask(displayTask);

    lightTask = new LightTask(&homeState, &sensorData);
    lightTask->init(500);
    sched.addTask(lightTask); 

    heatSysTask = new HeatingSysTask(&homeState, &sensorData);
    heatSysTask->init(100);
    sched.addTask(heatSysTask);

    alarmSysTask = new AlarmSysTask(&homeState);
    alarmSysTask->init(ALARM_TASK_EXEC_TIMEOUT);
    sched.addTask(alarmSysTask);
    
    garageTask = new GarageTask(&homeState.garageState);
    garageTask->init(40);
    sched.addTask(garageTask);
  
    bluetoothTask = new BluetoothTask(&homeState);
    bluetoothTask->init(2000);
    sched.addTask(bluetoothTask);

    serialCommTask = new SerialCommTask(&homeState, &sensorData);
    serialCommTask->init(2000);
    sched.addTask(serialCommTask);

}

void loop() {
    sched.schedule();
}