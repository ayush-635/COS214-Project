#ifndef HEAVYWATERINGSTRATEGY_H
#define HEAVYWATERINGSTRATEGY_H


#include "../WateringStrategy/WateringStrategy.h"
class PlantableArea;

class HeavyWateringStrategy : public WateringStrategy {
public:
    void waterPlant(PlantableArea* area);
};

#endif
