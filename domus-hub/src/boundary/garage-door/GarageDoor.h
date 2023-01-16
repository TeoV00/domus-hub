#ifndef __GARAGE_DOOR__
#define __GARAGE_DOOR__

#include "GarageState.h"
#include "servo_motor_impl.h"
#define MAX_DOOR_POS 180
#define MIN_DOOR_POS 0

class GarageDoor {
    private:
        int doorPosition = 0;
        GarageState state = GarageState::CLOSE;
        ServoMotor* motor;

    public:
        GarageDoor();
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void pause() = 0;
        virtual void updateDoor() = 0;
        virtual GarageState getState() = 0;

};

#endif