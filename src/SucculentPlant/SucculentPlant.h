#ifndef SUCCULENTPLANT_H
#define SUCCULENTPLANT_H

#include "src/Plant/Plant.h"

class SucculentPlant : public Plant {
public:
    SucculentPlant(const std::string& id, const std::string& name, 
                   std::shared_ptr<PlantData> data);
	SucculentPlant(const SucculentPlant& other) : Plant(other) { } // Copy constructor

	void accept(CareVisitor& visitor) override; 

	/*
	 * @brief Creates and returns a deep copy of the SucculentPlant instance.
	 * 
	 * @return Pointer to the newly cloned SucculentPlant instance.
	 * 
	 * @note Implements the clone method from the Plant base class.
	 */
	virtual Plant* clone() override;
};

#endif
