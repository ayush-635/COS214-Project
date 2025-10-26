#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H

#include "src/Plant/Plant.h"

class FlowerPlant : public Plant {
public:
    FlowerPlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    void accept(CareVisitor& visitor) override;
};

#endif