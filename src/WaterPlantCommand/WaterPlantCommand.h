#ifndef WATERPLANTCOMMAND_H
#define WATERPLANTCOMMAND_H

#include "../src/CareForPlantCommand/CareForPlantCommand.h"
#include "../src/WateringStrategy/WateringStrategy.h"




class WaterPlantCommand : public CareForPlantCommand {

public:
    WateringStrategy* wateringStrategy; 

    
    WaterPlantCommand(PlanterBoxCollection* collection, WateringStrategy* strategy, int index);

    
    void executeDuty() override;
};

#endif
