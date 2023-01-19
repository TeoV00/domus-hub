
#include "Arduino.h"
#include "PirSensor.h"

#define CALIBRATION_TIME_SEC 10

void PirSensor::calibrate() {
    Serial.print("Calibrazione sensore movimento... ");
    for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
        Serial.print(".");
        delay(1000);
    }
    Serial.println("calibrazione sensore finita");
}

bool PirSensor::motionDetect() {
    return digitalRead(this->getPin()) == HIGH;
}
