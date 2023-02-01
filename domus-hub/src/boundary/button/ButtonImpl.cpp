#include "boundary/button/ButtonImpl.h"
#include "Arduino.h"

#define BOUNCE_DELAY 200

bool ButtonImpl::isPressed() {
    bool isPressed = false;
    volatile int curTime = millis();
    if (curTime - this->lastTime >= BOUNCE_DELAY) {
        isPressed = digitalRead(this->getPin()) == LOW;
        this->lastTime = curTime;
    }
    return isPressed;
}
