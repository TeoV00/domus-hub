
#include "Task.h"
#include "Tasks/IndoorLightTask.h"

IndoorLightTask::IndoorLightTask(PowerState* lightState, Light* indoorLight) {
    this->lightState = lightState;
    this->light = indoorLight;
    this->updateLight();
}

void IndoorLightTask::init(int timeoutExec){
    Task::init(timeoutExec);
}

void IndoorLightTask::tick() {
    this->updateLight();
}

void IndoorLightTask::updateLight() {
    if (*this->lightState == PowerState::OFF) {
        this->light->switchOff();
    } else if (*this->lightState == PowerState::ON) {
        this->light->switchOff();
    }
}


