
#include "GarageTask.h"

GarageTask::GarageTask(GarageState* garageState, GarageDoor* garageDoor) {
    this->garageState = garageState;
    this->garageDoor = garageDoor;
}

void GarageTask::tick() {
    this->garageDoor->updateDoor();
}