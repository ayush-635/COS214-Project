#include "GrassPlant.h"
#include "src/CareVisitor/CareVisitor.h"

GrassPlant::GrassPlant(const std::string& id, const std::string& name, 
                       std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

void GrassPlant::accept(CareVisitor& visitor) {
    visitor.visitGrassPlant(this);
}