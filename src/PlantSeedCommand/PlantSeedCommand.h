#ifndef PLANTSEEDCOMMAND_H
#define PLANTSEEDCOMMAND_H

#include "Duty.h"
#include "PlanterBoxCollection.h"


/**
 * @brief Command to plant a seed in a specific planter box.
 */
class PlantSeedCommand : public Duty {
private:
    PlanterBoxCollection* collection; 
    Plant* seed;                      
    int boxIndex;                    

public:
    /**
     * @brief Constructor for PlantSeedCommand.
     * @param collection Pointer to the PlanterBoxCollection (row).
     * @param seed Pointer to the Plant to plant.
     * @param boxIndex Index of the planter box where the plant will be placed.
     */
    PlantSeedCommand(PlanterBoxCollection* collection, Plant* seed, int boxIndex);

    /**
     * @brief Executes the planting action on the specified planter box.
     */
    void executeDuty() override;
};

#endif
