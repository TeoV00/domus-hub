#ifndef __GARAGE_INTERFACE__
#define __GARAGE_INTERFACE__

class Garage {
    public:
        virtual void open() = 0;
        virtual void close() = 0;
        virtual void pause() = 0;
        virtual void updateDoor() = 0;
};

#endif
