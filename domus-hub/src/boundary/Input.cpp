
#include "Arduino.h"
#include "Input.h"

Input::Input(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

Input::getPin() {
    return this->pin;
}