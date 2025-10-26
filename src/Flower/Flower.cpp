#include "Flower.h"
#include "src/CareVisitor/CareVisitor.h"

Flower::Flower(const std::string& id, const std::string& name, 
               std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

void Flower::accept(CareVisitor& visitor) {
    visitor.visitFlower(this);
}