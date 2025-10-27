#ifndef WATERPLANTCOMMAND_H
#define WATERPLANTCOMMAND_H

#include "CareForPlantCommand.h"
#include "WateringStrategy.h"


/**
 * @class WaterPlantCommand
 * @brief Concrete command to water a PlantableArea using a specified strategy.
 */
class WaterPlantCommand : public CareForPlantCommand {
public:
    WateringStrategy* wateringStrategy; 

    /**
     * @brief Constructor
     * @param strategy Pointer to a WateringStrategy object
     */
    WaterPlantCommand(WateringStrategy* strategy);

    /**
     * @brief Executes the watering command on the given PlantableArea.
     * @param area Pointer to the PlantableArea to water
     */
    void executeDuty(PlantableArea* area);
};

#endif
