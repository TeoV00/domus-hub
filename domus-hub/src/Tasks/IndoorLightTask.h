#ifndef __LED_TASK_H__
#define __LED_TASK_H__

#include "HomeState.h"
#include "boundary/light/Light.h"

class IndoorLightTask : public Task {
    HomeState* homeState;
    Light* light;

    private:
        void updateLight();

    public:
        IndoorLightTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif