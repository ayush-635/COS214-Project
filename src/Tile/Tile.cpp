#include "Tile.h"

Tile::Tile(int id) : id(id), collection(new PlanterBoxCollection(0)) {}

int Tile::getId() const {
    return id;
}

PlanterBoxCollection* Tile::getPlantableArea() const {
    return collection;
}