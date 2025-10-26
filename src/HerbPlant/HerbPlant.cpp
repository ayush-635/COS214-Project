#include "HerbPlant.h"
#include "src/CareVisitor/CareVisitor.h"

HerbPlant::HerbPlant(const std::string& id, const std::string& name, 
                     std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

void HerbPlant::accept(CareVisitor& visitor) {
    visitor.visitHerbPlant(this);
}