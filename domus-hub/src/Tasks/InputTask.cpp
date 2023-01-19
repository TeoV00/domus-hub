
#include "Task.h"
#include "InputTask.h"
#include "InputValues.h"

InputTask::InputTask(InputValues* inputValues) {
    this->inputValues = inputValues;
}

void InputTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}

void InputTask::tick() {
    this->inputValues->btnAlarm = true;

}