#include "PirSensor.h"
#include "Arduino.h"

#define CALIBRATION_TIME_SEC 10

Pir::Pir(int pin) {
    this->pin = pin;
    pinMode(pin,INPUT);
}

void Pir::calibrate() {
    Serial.print("Calibrazione sensore movimento... ");
    for(int i = 0; i < CALIBRATION_TIME_SEC; i++){
        Serial.print(".");
        delay(1000);
    }
    Serial.println("calibrazione sensore finita");
}

bool Pir::motionDetect() {
    return digitalRead(this->pin) == HIGH;
}
