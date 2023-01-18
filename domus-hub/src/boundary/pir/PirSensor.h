#ifndef __PIR_SENSOR__
#define __PIR_SENSOR__

class Pir {
    private:
        int pin;
    public:
        Pir(int pin);
        /**
         * @brief Method to calibrate motion sensor, it is blockiing method, calibration takes some time.
         */
        virtual void calibrate() = 0;
        virtual bool motionDetect() = 0;
};

#endif