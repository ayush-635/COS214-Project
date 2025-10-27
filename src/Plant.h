#ifndef PLANT_H
#define PLANT_H

#include "PlantData.h"
#include "PlantState.h"
#include "PlantDataFactory.h"
#include "Pot.h"
#include <string>

class Plant : PlantDataFactory, PlantData { // Componennt in Composite

private:
	PlantState* state;
	int growthRate;
	PlantData* plantData;
	int health;
	int id;
	std::string name;
	Pot pot;

public:

	virtual Plant* clone() = 0;

	virtual void setGrowthRate(const std::string& season) = 0;

	void tick();

	std::string getName();
};

#endif // PLANT_H
