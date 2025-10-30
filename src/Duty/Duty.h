#ifndef DUTY_H
#define DUTY_H

#include "../PlanterBoxCollection/PlanterBoxCollection.h" 





class Duty {

protected:
    PlanterBoxCollection* collection;
    int index;

public:
   
    Duty(PlanterBoxCollection* collection, int index);

    
    virtual ~Duty();

    
    virtual void executeDuty() = 0;
};

#endif 
