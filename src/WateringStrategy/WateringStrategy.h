#ifndef WATERINGSTRATEGY_H
#define WATERINGSTRATEGY_H

#include "PlantableArea.h" 

/**
 * @class WateringStrategy
 * @brief Strategy interface for watering plants.
 *
 * Defines a method to water a PlantableArea. Concrete strategies
 * implement different watering intensities.
 */
class WateringStrategy {
public:
    WateringStrategy();
    virtual ~WateringStrategy();

    /**
     * @brief Water the plant(s) according to the strategy.
     */
    virtual void waterPlant(PlantableArea* area) = 0;
};

#endif
