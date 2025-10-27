#ifndef INTERMEDIATEWATERINGSTRATEGY_H
#define INTERMEDIATEWATERINGSTRATEGY_H

#include "WateringStrategy.h"

/**
 * @class IntermediateWateringStrategy
 * @brief Concrete strategy for intermediate watering.
 */
class IntermediateWateringStrategy : public WateringStrategy {
public:
    void waterPlant(PlantableArea* area);
};

#endif
