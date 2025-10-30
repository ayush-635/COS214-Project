#ifndef REMOVEPLANTCOMMAND_H
#define REMOVEPLANTCOMMAND_H

#include "../Duty/Duty.h"
class Plant;
class PlanterBoxCollection;


class RemovePlantCommand : public Duty {
private:
    
    Plant* targetPlant;               
                     

public:
   
    RemovePlantCommand(PlanterBoxCollection* collection, Plant* targetPlant, int index);

    
    void executeDuty() override;
};

#endif
