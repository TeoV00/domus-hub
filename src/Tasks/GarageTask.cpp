
#include "GarageTask.h"
#include "boundary/garage-door/GarageDoor.h"
#include <HardwareSerial.h>
#include "boundary/garage-door/GarageState.h"

GarageTask::GarageTask(GarageState* garageState) {
    this->garageDoor = new GarageDoor(garageState);
    this->garageState = garageState;
}

void GarageTask::init(int timeoutExec) {
    Task::init(timeoutExec);
    garageDoor->close();
}

void GarageTask::tick() {
    GarageState state = this->getGarageState();
    if(state == GarageState::REQ_OPEN) {
        this->garageDoor->open();
    } else if(state == GarageState::REQ_CLOSE) {
        this->garageDoor->close();
    } else if (state == GarageState::REQ_PAUSE) {
        this->garageDoor->pause();
    }
    this->garageDoor->updateDoor();
}

GarageState GarageTask::getGarageState() {
    return *this->garageState;
}