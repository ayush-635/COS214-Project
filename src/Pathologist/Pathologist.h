#ifndef PATHOLOGIST_H
#define PATHOLOGIST_H

#include "../StaffMember/StaffMember.h"

class Pathologist : public StaffMember {
    public:
        virtual ~Pathologist(){};

        virtual void tick();

        virtual void receivePreference();
        
        virtual void browse();

        virtual void sendAdvice();
};

#endif
