#ifndef __BTN_STATE_MANAGER__
#define __BTN_STATE_MANAGER__

#include "Input.h"
#include "Button.h"
#define MAX_NUM_INPUTS 5

class InputManager {
    private:
        Input* inputs[MAX_NUM_INPUTS];
        
    
    public:
        InputManager();
        void syncInputs() {
            for(int i = 0; i < MAX_NUM_INPUTS; i++) {
                if (inputs[i] != nullptr) {
                    inputs[i]->readValue();
                }
            }
        }
        bool isHeatingBtnPressed();
        bool isAlarmBtnPressed();

};

#endif