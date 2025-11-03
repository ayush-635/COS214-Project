#ifndef CACTUS_H
#define CACTUS_H

#include "Plant.h"

class Cactus : public Plant {
public:
    Cactus(const std::string& id, const std::string& name, 
           std::shared_ptr<PlantData> data);
    void accept(CareVisitor& visitor) override;
};

#endif