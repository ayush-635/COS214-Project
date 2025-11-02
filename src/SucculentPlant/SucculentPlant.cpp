#include "../SucculentPlant/SucculentPlant.h"
#include "../CareVisitor/CareVisitor.h"

SucculentPlant::SucculentPlant(const std::string& id, const std::string& name, 
                               std::shared_ptr<PlantData> data) : Plant(id, name, data) {}

Plant* SucculentPlant::clone() {
    return new SucculentPlant(*this);
}

void SucculentPlant::accept(CareVisitor& visitor) {
    visitor.visitSucculentPlant(this);
}