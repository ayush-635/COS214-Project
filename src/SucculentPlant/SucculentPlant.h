#ifndef SUCCULENTPLANT_H
#define SUCCULENTPLANT_H

#include "src/Plant/Plant.h"

class SucculentPlant : public Plant {
public:
    SucculentPlant(const std::string& id, const std::string& name, 
                   std::shared_ptr<PlantData> data);
	SucculentPlant(const SucculentPlant& other) : Plant(other) { }

	void accept(CareVisitor& visitor) override;
	virtual Plant* clone() override;
};
