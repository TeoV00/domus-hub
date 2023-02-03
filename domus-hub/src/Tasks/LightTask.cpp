
#include "Task.h"
#include "Tasks/LightTask.h"
#include "boundary/light/Led.h"
#include "boundary/light/DimmLed.h"
#include "PinSetup.h"
#include "Arduino.h"

#define MAX_LIGHT 1024
#define MAX_LIGHT_MAP 5
#define MIN_LED_BRIGTH 10
#define MAX_LED_BRIGTH 255
#define TRESHOLD_LIGHT 3

LightTask::LightTask(HomeState* homeState, HomeSensorData* homeSensorData) {
    this->homeState = homeState;
    this->homeSensorData = homeSensorData;
    this->indoorLight = new Led(INDOOR_LIGHT_PIN);
    this->outdoorLight = new DimmLed(OUTDOOR_LIGHT_PIN);
    this->tick();
}

void LightTask::init(int timeoutExec){
    Task::init(timeoutExec);
}

void LightTask::tick() {
    this->updateLight();
    unsigned int mappedLight = map(this->homeSensorData->extLight,0, MAX_LIGHT, 0, MAX_LIGHT_MAP);
    if (mappedLight < TRESHOLD_LIGHT) {
        unsigned int ledBright = (MAX_LIGHT/MAX_LED_BRIGTH)*this->homeSensorData->extLight;
        this->homeState->outLight = ledBright; // update homeState
        this->outdoorLight->setBrightness(ledBright); // set outdoorlight brigth
    } else {
        this->homeState->outLight = 0;
        this->outdoorLight->setBrightness(0);
    }
}

void LightTask::updateLight() {
    if (this->homeState->inLight == PowerState::OFF) {
        this->indoorLight->switchOff();
    } else if (this->homeState->inLight == PowerState::ON) {
        this->indoorLight->switchOn();
    }
}
