/**
 * @file HeavyWateringStrategy.h
 * @brief Declares the HeavyWateringStrategy class, which implements a deep watering approach.
 */

#ifndef HEAVYWATERINGSTRATEGY_H
#define HEAVYWATERINGSTRATEGY_H

#include "../src/WateringStrategy/WateringStrategy.h"
class PlantableArea;

/**
 * @class HeavyWateringStrategy
 * @brief Concrete watering strategy that applies a large amount of water to plants.
 *
 * This strategy is suitable for plants that thrive in moist conditions or require deep watering.
 */
class HeavyWateringStrategy : public WateringStrategy {
public:
    /**
     * @brief Applies a heavy watering method to the given plantable area.
     * @param area Pointer to the PlantableArea object to be watered.
     */
    void waterPlant(PlantableArea* area) override;
};

#endif
