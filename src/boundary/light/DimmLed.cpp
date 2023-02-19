#include "DimmLed.h"
#include "Arduino.h"
#include "Led.h"

void DimmLed::switchOff() {
    Led::switchOff();
}

void DimmLed::switchOn() {
    Led::switchOn();
}
void DimmLed::setBrightness(unsigned char value) {
    analogWrite(Led::pin, value);
}