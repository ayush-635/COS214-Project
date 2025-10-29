#ifndef SALES_H
#define SALES_H

#include "../StaffMember/StaffMember.h"

class Sales : public StaffMember {

    public:
        virtual ~Sales(){};

        virtual void tick(int time);

        virtual void receivePreference();
        
        virtual void browse();

        virtual void sendAdvice();
};

#endif
