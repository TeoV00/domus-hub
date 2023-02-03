#ifndef __LED_TASK_H__
#define __LED_TASK_H__

#include "HomeState.h"
#include "HomeSensorData.h"
#include "boundary/light/Light.h"
#include "boundary/light/DimmLight.h"

class LightTask : public Task {
    HomeState* homeState;
    HomeSensorData* homeSensorData;
    Light* indoorLight;
    DimmLight* outdoorLight;

    private:
        void updateLight();

    public:
        LightTask(HomeState* homeState, HomeSensorData* homeSensorData);
        void init(int timeoutExec);
        void tick();
};

#endif