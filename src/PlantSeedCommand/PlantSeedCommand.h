#ifndef PLANTSEEDCOMMAND_H
#define PLANTSEEDCOMMAND_H

#include "../Duty/Duty.h"
class PlanterBoxCollection;
class Plant;




class PlantSeedCommand : public Duty {
private:
  
Plant* seed;                      
                      

public:
    
    PlantSeedCommand(PlanterBoxCollection* collection, Plant* seed, int index);

   
    void executeDuty() override;
};

#endif
