
#include "Task.h"
#include "Tasks/LightTask.h"
#include "boundary/light/Led.h"
#include "boundary/light/DimmLed.h"
#include "PinSetup.h"

LightTask::LightTask(HomeState* homeState) {
    this->homeState = homeState;
    this->indoorLight = new Led(INDOOR_LIGHT_PIN);
    this->alarmLight = new Led(ALARM_LIGHT_PIN);
    this->outdoorLight = new DimmLed(OUTDOOR_LIGHT_PIN);
    this->updateLight();
}

void LightTask::init(int timeoutExec){
    Task::init(timeoutExec);
}

void LightTask::tick() {
    this->updateLight();
    this->outdoorLight->setBrightness(this->homeState->outLight);
}

void LightTask::updateLight() {
    if (this->homeState->inLight == PowerState::OFF) {
        this->indoorLight->switchOff();
    } else if (this->homeState->inLight == PowerState::ON) {
        this->indoorLight->switchOn();
    }
}


