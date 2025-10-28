#ifndef REMOVEPLANTCOMMAND_H
#define REMOVEPLANTCOMMAND_H

#include "Duty.h"
#include "PlanterBoxCollection.h"


/**
 * @brief Command to remove a plant from a specific planter box.
 */
class RemovePlantCommand : public Duty {
private:
    PlanterBoxCollection* collection; 
    Plant* targetPlant;               
    int boxIndex;                    

public:
    /**
     * @brief Constructor for RemovePlantCommand.
     * @param collection Pointer to the PlanterBoxCollection (row).
     * @param targetPlant Pointer to the plant to remove.
     * @param boxIndex Index of the planter box from which to remove the plant.
     */
    RemovePlantCommand(PlanterBoxCollection* collection, Plant* targetPlant, int boxIndex);

    /**
     * @brief Executes the removal action on the specified planter box.
     */
    void executeDuty() override;
};

#endif
