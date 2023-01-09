#ifndef __TASK__
#define __TASK__

class Task {
    int timeoutExec;
    int timeElasped;
    bool isEnable;

    public:
        
        virtual void init(int timeoutExec) {
            this->timeoutExec = timeoutExec;
            timeElasped = 0;
            this->enable();
        };

        bool checkIfTimeToExec(int timeUnit) {
            timeElasped += timeUnit;
            if(timeElasped >= timeoutExec) {
                //reset timeElasped counter
                timeElasped = 0;
                return true;
            }
            else{
                return false;
            }
        }

        bool isEnabled() {
            return this->isEnable;
        }

        void disable() {
            this->isEnable = false;
        }

        void enable() {
            this->isEnable = true;
        }

        virtual void tick() = 0;
};

#endif
