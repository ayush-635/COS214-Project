#ifndef LIGHTWATERINGSTRATEGY_H
#define LIGHTWATERINGSTRATEGY_H


#include "../src/WateringStrategy/WateringStrategy.h"
class PlantableArea;



class LightWateringStrategy : public WateringStrategy {
public:
    void waterPlant(PlantableArea* area);
};

#endif

