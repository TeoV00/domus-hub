
#include "GarageTask.h"
#include "boundary/garage-door/GarageDoor.h"

GarageTask::GarageTask(Data* data) {
    this->garageDoor = new GarageDoor();
    this->data = data;
}

void GarageTask::init(int timeoutExec) {
    Task::init(timeoutExec);
}

void GarageTask::tick() {
    GarageState state = this->data->garageState;
    if(state == REQ_OPEN) {
        this->garageDoor->open();
    } else if(state == REQ_CLOSE) {
        this->garageDoor->close();
    }
    this->garageDoor->updateDoor();
}