#include "Cactus.h"
#include "../CareVisitor/CareVisitor.h"

Cactus::Cactus(const std::string& id, const std::string& name, 
               std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

void Cactus::accept(CareVisitor& visitor) {
    visitor.visitCactus(this);
}