#ifndef FLOWER_H
#define FLOWER_H

#include "src/Plants/Plant.h"

class Flower : public Plant {
public:
    Flower(const std::string& id, const std::string& name, 
           std::shared_ptr<PlantData> data);
    void accept(CareVisitor& visitor) override;
};

#endif