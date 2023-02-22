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
SerialCommTask* serialCommTask;
HeatingSysTask* heatSysTask;
AlarmSysTask* alarmSysTask;
BluetoothTask* bluetoothTask;

void setup() {
    Serial.begin(9600);
    
    sched.init(SCHED_PERIOD);

    displayTask = new DisplayTask(&homeState);
    displayTask->init(500);
    sched.addTask(displayTask);

    lightTask = new LightTask(&homeState, &sensorData);
    lightTask->init(500);
    sched.addTask(lightTask); 

    heatSysTask = new HeatingSysTask(&homeState, &sensorData);
    heatSysTask->init(200);
    sched.addTask(heatSysTask);

    alarmSysTask = new AlarmSysTask(&homeState);
    alarmSysTask->init(ALARM_TASK_EXEC_TIMEOUT);
    sched.addTask(alarmSysTask);

    serialCommTask = new SerialCommTask(&homeState, &sensorData);
    serialCommTask->init(2000);
    sched.addTask(serialCommTask);
    
    garageTask = new GarageTask(&homeState.garageState);
    garageTask->init(40);
    sched.addTask(garageTask);
  
    bluetoothTask = new BluetoothTask(&homeState);
    bluetoothTask->init(2000);
    sched.addTask(bluetoothTask);

}

void loop() {
    sched.schedule();
}