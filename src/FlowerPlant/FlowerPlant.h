#ifndef FLOWERPLANT_H
#define FLOWERPLANT_H

#include "src/Plant/Plant.h"

class FlowerPlant : public Plant {
public:
    FlowerPlant(const std::string& id, const std::string& name, 
                std::shared_ptr<PlantData> data);
    FlowerPlant(const FlowerPlant& other) : Plant(other) { }

    void accept(CareVisitor& visitor) override;
	
	virtual Plant* clone() override;
};

#endif