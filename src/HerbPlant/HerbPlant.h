#ifndef HERBPLANT_H
#define HERBPLANT_H

#include "src/Plant/Plant.h"

class HerbPlant : public Plant {
public:
    HerbPlant(const std::string& id, const std::string& name, 
              std::shared_ptr<PlantData> data);
	HerbPlant(const HerbPlant& other) : Plant(other) { }

    void accept(CareVisitor& visitor) override;

	virtual Plant* clone();
};

#endif