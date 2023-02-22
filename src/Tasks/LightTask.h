#ifndef __LED_TASK_H__
#define __LED_TASK_H__

#include "HomeState.h"
#include "SensorData.h"
#include "boundary/light/Light.h"
#include "boundary/light/DimmLight.h"

class LightTask : public Task {

    private:
        HomeState* homeState;
        SensorData* homeSensorData;
        Light* indoorLight;
        DimmLight* outdoorLight;
        void updateLight();
        bool checkSwitchOnLight(int extLightValue);

    public:
        LightTask(HomeState* homeState, SensorData* homeSensorData);
        void init(int timeoutExec);
        void tick();
};

#endif