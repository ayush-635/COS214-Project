#ifndef HERBPLANT_H
#define HERBPLANT_H

#include "src/Plant/Plant.h"

class HerbPlant : public Plant {
public:
    HerbPlant(const std::string& id, const std::string& name, 
              std::shared_ptr<PlantData> data);
    void accept(CareVisitor& visitor) override;
};

#endif