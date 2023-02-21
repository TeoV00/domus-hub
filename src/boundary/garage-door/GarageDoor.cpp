
#include "GarageDoor.h"
#include "GarageState.h"
#include "servo_motor_impl.h"
#include "PinSetup.h"
#define INC_POS 1
#define DEC_POS -1

GarageDoor::GarageDoor(GarageState* garageHomeState) {
    this->garageHomeState = garageHomeState;
    this->motor = new ServoMotorImpl(SERVO_PWM);
    this->motor->on();
    this->motor->setPosition(MIN_DOOR_POS);
}

void GarageDoor::open() {
    if (this->getState() != GarageState::OPEN ||
        this->getState() != GarageState::OPENING) {
        *this->garageHomeState = GarageState::OPENING;
    }
}

void GarageDoor::close() {
    if (this->getState() != GarageState::CLOSE || 
        this->getState() != GarageState::CLOSING) {
        *this->garageHomeState= GarageState::CLOSING;
    }
}

void GarageDoor::updateDoor() {
    GarageState state = this->getState();
    int step = state == GarageState::CLOSING ? DEC_POS : INC_POS; // By default position is incremented
    
    if ((state == GarageState::OPENING && this->doorPosition < MAX_DOOR_POS) || 
        (state == GarageState::CLOSING && this->doorPosition > MIN_DOOR_POS)) {
        this->doorPosition += step;
        this->motor->on();
        this->motor->setPosition(this->doorPosition);
    } else {
       this->motor->off();
    }
    if (this->doorPosition <= MIN_DOOR_POS) {
        *this->garageHomeState = GarageState::CLOSE;
    } else if (this->doorPosition >= MAX_DOOR_POS) {
        *this->garageHomeState = GarageState::OPEN;
    }
}

void GarageDoor::pause() {
    GarageState curState = *this->garageHomeState;
    if (curState == GarageState::REQ_PAUSE) {
        *this->garageHomeState = GarageState::PAUSE;
    }
}
