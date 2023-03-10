
#include "Task.h"
#include "Tasks/LightTask.h"
#include "boundary/light/Led.h"
#include "boundary/light/DimmLed.h"
#include "PinSetup.h"
#include "Arduino.h"

#define MAX_LIGHT 4096
#define MAX_LIGHT_MAP 5
#define MIN_LED_BRIGTH 20
#define MAX_LED_BRIGTH 255
#define TRESHOLD_LIGHT 3

LightTask::LightTask(HomeState* homeState, SensorData* homeSensorData) {
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
    int extLight = this->homeSensorData->extLight;
    
    if (this->homeState->btConnected == 0 && this->homeState->alarmState != AlarmState::RINGING) {
        if(this->checkSwitchOnLight(extLight)) {
            // map external light to led values, set outdoor light inversely proportional to external one
            int ledBright = MAX_LED_BRIGTH - map(extLight, 0, MAX_LIGHT, MIN_LED_BRIGTH, MAX_LED_BRIGTH);
            this->homeState->outLight = ledBright; // update homeState
            this->outdoorLight->setBrightness(ledBright); // set outdoorlight brigth
        } else {
            this->homeState->outLight = 0;
            this->outdoorLight->setBrightness(0);
        }
    } else {
        this->outdoorLight->setBrightness(this->homeState->outLight);
    }
    
}

void LightTask::updateLight() {
    if (this->homeState->inLight == PowerState::OFF) {
        this->indoorLight->switchOff();
    } else if (this->homeState->inLight == PowerState::ON) {
        this->indoorLight->switchOn();
    }
}

bool LightTask::checkSwitchOnLight(int extLightValue) {
    return map(extLightValue, 0, MAX_LIGHT, 0, MAX_LIGHT_MAP) < TRESHOLD_LIGHT;
}