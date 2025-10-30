#ifndef REMOVEPLANTCOMMAND_H
#define REMOVEPLANTCOMMAND_H

#include "../src/Duty/Duty.h"
#include "../src/Plant/Plant.h"


class RemovePlantCommand : public Duty {
private:
    
    Plant* targetPlant;               
                     

public:
   
    RemovePlantCommand(PlanterBoxCollection* collection, Plant* targetPlant, int index);

    
    void executeDuty() override;
};

#endif
