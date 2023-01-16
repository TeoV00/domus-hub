#ifndef __LED_TASK_H__
#define __LED_TASK_H__

#include "Data.h"
#include "boundary/light/Light.h"

class IndoorLightTask : public Task {
    PowerState* lightState;
    Light* light;

    private:
        void updateLight();

    public:
        IndoorLightTask(PowerState* lightState, Light* indoorLight);
        void init(int timeoutExec);
        void tick();
};

#endif