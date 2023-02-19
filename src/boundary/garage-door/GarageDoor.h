#ifndef __GARAGE_DOOR__
#define __GARAGE_DOOR__

#include "GarageState.h"
#include "HomeState.h"
#include "servo_motor_impl.h"
#include "Garage.h"

#define MAX_DOOR_POS 180
#define MIN_DOOR_POS 5

class GarageDoor : public Garage {
    private:
        int doorPosition = MIN_DOOR_POS;
        HomeState* state;
        ServoMotor* motor;

    public:
        GarageDoor(HomeState* state);
        void open();
        void close();
        void pause();
        void updateDoor();
        GarageState getState() {
            return this->state->garageState;
        };
};

#endif