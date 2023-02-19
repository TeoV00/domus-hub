#ifndef __PIR_SENSOR__
#define __PIR_SENSOR__

#include "MotionSensor.h"
#include "boundary/Input.h"

class PirSensor : public MotionSensor, public Input {
    public:
        PirSensor(int pin) : Input(pin) {};
        void calibrate();
        bool motionDetect();
};

#endif