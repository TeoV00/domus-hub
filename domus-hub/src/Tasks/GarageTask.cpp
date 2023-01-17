
#include "GarageTask.h"
#include "boundary/garage-door/GarageDoor.h"

GarageTask::GarageTask(HomeState* homeState) {
    this->garageDoor = new GarageDoor();
    this->homeState = homeState;
}

void GarageTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}

void GarageTask::tick() {
    GarageState state = this->homeState->garageState;
    if(state == REQ_OPEN) {
        this->garageDoor->open();
    } else if(state == REQ_CLOSE) {
        this->garageDoor->close();
    }
    this->garageDoor->updateDoor();
}