/**
 * @file WaterPlantCommand.h
 * @brief Defines the WaterPlantCommand class, which waters a plant using a given strategy.
 */
#ifndef WATERPLANTCOMMAND_H
#define WATERPLANTCOMMAND_H
#include "../WateringStrategy/WateringStrategy.h"
#include "../CareForPlantCommand/CareForPlantCommand.h"

/* class WateringStrategy;
class PlanterBoxCollection; */

/**
 * @class WaterPlantCommand
 * @brief Command that waters a plant according to a specified watering strategy.
 */
class WaterPlantCommand : public CareForPlantCommand {
public:
    WateringStrategy* wateringStrategy;///< Strategy used to determine watering behavior.

    /**
     * @brief Constructs a WaterPlantCommand.
     * @param collection Pointer to the planter box collection.
     * @param strategy Pointer to the watering strategy.
     * @param index The index of the target planter box.
     */
    WaterPlantCommand(PlanterBoxCollection* collection, WateringStrategy* strategy, int index);

    /**
     * @brief Executes the watering operation.
     */
    void executeDuty() override;
};

#endif
