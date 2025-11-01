#include "FlowerPlant.h"
#include "../CareVisitor/CareVisitor.h"

FlowerPlant::FlowerPlant(const std::string& id, const std::string& name, 
                         std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

Plant* FlowerPlant::clone() {
    return new FlowerPlant(*this);
}

void FlowerPlant::accept(CareVisitor& visitor) {
    visitor.visitFlowerPlant(this);

}
