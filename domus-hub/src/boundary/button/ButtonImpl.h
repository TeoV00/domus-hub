#ifndef __BUTTONIMPL__
#define __BUTTONIMPL__

class ButtonImpl{
    private:
        int pin;
    public: 
        ButtonImpl(int pin);
        bool isPressed();
};

#endif
