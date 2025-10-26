#ifndef GRASSPLANT_H
#define GRASSPLANT_H

#include "src/Plant/Plant.h"

class GrassPlant : public Plant {
public:
    GrassPlant(const std::string& id, const std::string& name, 
               std::shared_ptr<PlantData> data);
    void accept(CareVisitor& visitor) override;
};

#endif