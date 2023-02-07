#ifndef __SWITCH_BUTTON__
#define __SWITCH_BUTTON__

class SwitchButton {
    public:
        virtual bool isSwitchedOn() = 0;
        virtual void forceOff() = 0;
};

#endif
