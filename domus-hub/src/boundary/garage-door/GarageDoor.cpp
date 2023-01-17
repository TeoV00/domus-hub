
#include "GarageDoor.h"
#include "servo_motor_impl.h"
#include "PinSetup.h"
#define INC_POS 1
#define DEC_POS -1

GarageDoor::GarageDoor(HomeState* homeState) {
    this->state = homeState;
    this->motor = new ServoMotorImpl(SERVO_PWM);
    this->motor->on();
    this->motor->setPosition(this->doorPosition);
}

void GarageDoor::open() {
    if (this->getState() != GarageState::OPEN && 
        this->getState() != GarageState::OPENING &&
        this->getState() != GarageState::OPENING_P) {
        this->state->garageState = GarageState::OPENING;
    }
}

void GarageDoor::close() {
    if (this->getState() != GarageState::CLOSE && 
        this->getState() != GarageState::CLOSING && 
        this->getState() != GarageState::CLOSING_P) {
        this->state->garageState = GarageState::CLOSING;
    }
}

void GarageDoor::updateDoor() {
    GarageState state = this->getState();
    int pos = this->doorPosition;
    int step = state == GarageState::CLOSING ? DEC_POS : INC_POS; // By default position is incremented
    
    if ((state == GarageState::OPENING && pos < MAX_DOOR_POS) || 
        (state == GarageState::CLOSING && pos > MIN_DOOR_POS)) {
        this->doorPosition += step;
        this->motor->on();
        this->motor->setPosition(this->doorPosition);
    } else {
        this->motor->off();
    }
    if (pos <= MIN_DOOR_POS) {
        this->state->garageState = GarageState::CLOSE;
    } else if (pos >= MAX_DOOR_POS) {
         this->state->garageState = GarageState::OPEN;
    }
}

void GarageDoor::pause() {
    GarageState curState = this->state->garageState;
    if (curState == GarageState::CLOSING) {
         this->state->garageState = GarageState::CLOSING_P;
    } else if (curState == GarageState::OPENING) {
         this->state->garageState = GarageState::OPENING_P;
    } else if (curState == GarageState::OPENING_P) {
         this->state->garageState = GarageState::OPENING;
    } else if (curState == GarageState::CLOSING_P) {
         this->state->garageState = GarageState::CLOSING;
    }
}
