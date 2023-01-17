#ifndef __LED_TASK_H__
#define __LED_TASK_H__

#include "HomeState.h"
#include "boundary/light/Light.h"
#include "boundary/light/DimmLight.h"

class LightTask : public Task {
    HomeState* homeState;
    Light* indoorLight;
    Light* alarmLight;
    DimmLight* outdoorLight;

    private:
        void updateLight();

    public:
        LightTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif