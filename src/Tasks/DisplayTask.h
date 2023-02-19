#ifndef __DISPLAY_TASK__
#define __DISPLAY_TASK__

#include "Task.h"
#include "HomeState.h"
#include "boundary/display/Display.h"

class DisplayTask : public Task {
    private:
        Display* display;
        HomeState* homeState;
        void updateDisplay();

    public:
        DisplayTask(HomeState* homeState);
        void init(int timeoutExec);
        void tick();
};

#endif