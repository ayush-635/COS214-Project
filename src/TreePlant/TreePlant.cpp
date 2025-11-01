#include "../TreePlant/TreePlant.h"
#include "../CareVisitor/CareVisitor.h"

TreePlant::TreePlant(const std::string& id, const std::string& name, 
                     std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

Plant* TreePlant::clone() {
    return new TreePlant(*this);
}

void TreePlant::accept(CareVisitor& visitor) {
    visitor.visitTreePlant(this);
}