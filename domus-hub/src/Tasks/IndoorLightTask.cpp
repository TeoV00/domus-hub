
#include "Task.h"
#include "Tasks/IndoorLightTask.h"
#include "boundary/light/Led.h"
#include "PinSetup.h"

IndoorLightTask::IndoorLightTask(HomeState* homeState) {
    this->homeState = homeState;
    this->light = new Led(INDOOR_LIGHT_PIN);
    this->updateLight();
}

void IndoorLightTask::init(int timeoutExec){
    Task::init(timeoutExec);
}

void IndoorLightTask::tick() {
    this->updateLight();
}

void IndoorLightTask::updateLight() {
    if (this->homeState->inLight == PowerState::OFF) {
        this->light->switchOff();
    } else if (this->homeState->inLight == PowerState::ON) {
        this->light->switchOn();
    }
}


