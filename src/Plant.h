#ifndef PLANT_H
#define PLANT_H

class Plant : PlantDataFactory, PlantData {

private:
	PlantState state;
	int growthRate;
	PlantData* plantData;
	int health;
	int id;
	string name;
	Pot pot;

public:
	virtual Plant* clone() = 0;

	virtual void setGrowthRate(int std::string_season) = 0;

	void tick();
};

#endif
