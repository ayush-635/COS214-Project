/**
 * @file IntermediateWateringStrategy.h
 * @brief Declares the IntermediateWateringStrategy class, which implements a moderate watering approach.
 */
#ifndef INTERMEDIATEWATERINGSTRATEGY_H
#define INTERMEDIATEWATERINGSTRATEGY_H
#include "../WateringStrategy/WateringStrategy.h"

/**
 * @class IntermediateWateringStrategy
 * @brief Concrete watering strategy that applies a balanced, moderate amount of water.
 *
 * This strategy is suitable for plants that require a normal watering schedule.
 */
class IntermediateWateringStrategy : public WateringStrategy {
public:
    /**
     * @brief Applies an intermediate watering method to the given plantable area.
     * @param area Pointer to the PlantableArea object to be watered.
     */
    void waterPlant(PlantableArea* area);
};

#endif
