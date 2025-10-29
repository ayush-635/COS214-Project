#ifndef GARDNER_H
#define GARDNER_H

#include "../StaffMember/StaffMember.h"

class Gardner : public StaffMember {
    public:
        virtual ~Gardner(){};

        virtual void tick(int time);

        virtual void receivePreference();
        
        virtual void browse();

        virtual void sendAdvice();
};

#endif
