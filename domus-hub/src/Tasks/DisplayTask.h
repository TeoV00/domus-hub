#ifndef __DISPLAY_TASK__
#define __DISPLAY_TASK__

#include "Task.h"
#include "Data.h"
#include "boundary/display/Display.h"

class DisplayTask : public Task {
    private:
        Display* display;
        Data* data;
        void updateDisplay();

    public:
        DisplayTask(Data* data);
        void init(int timeoutExec);
        void tick();
};

#endif