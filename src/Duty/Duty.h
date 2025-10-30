#ifndef DUTY_H
#define DUTY_H

class PlantableArea;
#include "../src/PlantableArea/PlantableArea.h"
#include "../src/PlanterBoxCollection/PlanterBoxCollection.h"
#include <iostream>


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
