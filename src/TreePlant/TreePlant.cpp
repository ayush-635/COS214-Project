#include "TreePlant.h"
#include "../CareVisitor/CareVisitor.h"

TreePlant::TreePlant(const std::string& id, const std::string& name, 
                     std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

void TreePlant::accept(CareVisitor& visitor) {
    visitor.visitTreePlant(this);
}