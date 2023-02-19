#ifndef __MOTION_SENSOR__
#define __MOTION_SENSOR__

class MotionSensor {
    public:
        /**
         * @brief Method to calibrate motion sensor, it is blockiing method, calibration takes some time.
         */
        virtual void calibrate() = 0;
        virtual bool motionDetect() = 0;

};
#endif