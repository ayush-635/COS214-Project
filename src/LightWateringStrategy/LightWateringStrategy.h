#ifndef LIGHTWATERINGSTRATEGY_H
#define LIGHTWATERINGSTRATEGY_H
#include "../WateringStrategy/WateringStrategy.h"
class LightWateringStrategy : public WateringStrategy {
public:
    void waterPlant(PlantableArea* area);
};

#endif

