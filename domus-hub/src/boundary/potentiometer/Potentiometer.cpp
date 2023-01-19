#include "Arduino.h"
#include "Potentiometer.h"

int Potentiometer::readValue() {
    return analogRead(this->getPin());
}