#ifndef WATERPLANTCOMMAND_H
#define WATERPLANTCOMMAND_H


#include "../src/CareForPlantCommand/CareForPlantCommand.h"
class WateringStrategy;
class PlanterBoxCollection;



class WaterPlantCommand : public CareForPlantCommand {

public:
    WateringStrategy* wateringStrategy; 

    
    WaterPlantCommand(PlanterBoxCollection* collection, WateringStrategy* strategy, int index);

    
    void executeDuty() override;
};

#endif
