#include "boundary/button/ButtonImpl.h"
#include "Arduino.h"

bool ButtonImpl::isPressed(){
    return digitalRead(this->getPin()) == HIGH;
}
