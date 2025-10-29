#include "HerbPlant.h"
#include "../CareVisitor/CareVisitor.h"

HerbPlant::HerbPlant(const std::string& id, const std::string& name, 
                     std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

Plant* HerbPlant::clone() {
    return new HerbPlant(*this);
}

void HerbPlant::accept(CareVisitor& visitor) {
    visitor.visitHerbPlant(this);
}