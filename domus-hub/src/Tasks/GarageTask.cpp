
#include "GarageTask.h"
#include "boundary/garage-door/GarageDoor.h"
#include <HardwareSerial.h>
#include "boundary/garage-door/GarageState.h"

GarageTask::GarageTask(HomeState* homeState) {
    this->garageDoor = new GarageDoor(homeState);
    this->homeState = homeState;
}

void GarageTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}

void GarageTask::tick() {
    GarageState state = this->homeState->garageState;
    if (this->homeState->moveDetected == true && (state != GarageState::CLOSE || state != GarageState::CLOSING)) {
        this->garageDoor->close();
    }
    else if(state == GarageState::REQ_OPEN) {
        this->garageDoor->open();
    } else if(state == GarageState::REQ_CLOSE) {
        this->garageDoor->close();
    }
    this->garageDoor->updateDoor();
}