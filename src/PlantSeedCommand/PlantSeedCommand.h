/**
 * @file PlantSeedCommand.h
 * @brief Defines the PlantSeedCommand class, which handles planting a seed in a specified planter box.
 */

#ifndef PLANTSEEDCOMMAND_H
#define PLANTSEEDCOMMAND_H

#include "../Duty/Duty.h"

class PlanterBoxCollection;
class Plant;

/**
 * @class PlantSeedCommand
 * @brief A concrete command that plants a seed in a specified planter box within a collection.
 *
 * This class implements the Command design pattern. It inherits from Duty
 * and encapsulates the action of planting a given Plant object into a specific
 * PlanterBox within the provided PlanterBoxCollection.
 */
class PlantSeedCommand : public Duty {
private:
    /**
     * @brief Pointer to the Plant object (seed) that will be planted.
     */
    Plant* seed;

public:
    /**
     * @brief Constructs a PlantSeedCommand object.
     * @param collection Pointer to the PlanterBoxCollection where the seed will be planted.
     * @param seed Pointer to the Plant object representing the seed to be planted.
     * @param index The index of the target planter box within the collection.
     */
    PlantSeedCommand(PlanterBoxCollection* collection, Plant* seed, int index);

    /**
     * @brief Executes the planting duty by planting the seed in the specified planter box.
     */
    void executeDuty() override;
};

#endif // PLANTSEEDCOMMAND_H

