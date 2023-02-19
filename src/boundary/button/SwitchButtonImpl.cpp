#include "boundary/button/SwitchButtonImpl.h"

bool SwitchButtonImpl::isSwitchedOn() {
    if (this->isPressed()) {
        this->isSwitchOn = ! this->isSwitchOn;
    }
    return this->isSwitchOn;
}

void SwitchButtonImpl::forceOff() {
    this->isSwitchOn = false;
}