#ifndef TILE_H
#define TILE_H

#include "PlanterBoxCollection.h"

class Tile {
    private:
        int id;
        PlanterBoxCollection* collection;
    public:
        Tile(int id);
        int getId() const;
        PlanterBoxCollection* getPlantableArea() const;
};

#endif // TILE_H