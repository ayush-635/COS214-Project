#ifndef WATERPLANTCOMMAND_H
#define WATERPLANTCOMMAND_H

#include "CareForPlantCommand.h"
#include "WateringStrategy.h"
#include "PlanterBoxCollection.h"



class WaterPlantCommand : public CareForPlantCommand {

private:
    PlanterBoxCollection* collection; 
    int boxIndex;

public:
    WateringStrategy* wateringStrategy; 

    
    WaterPlantCommand(PlanterBoxCollection* collection, int boxIndex, WateringStrategy* strategy);

    
    void executeDuty(PlantableArea* area) override;
};

#endif
