#ifndef PLANT2_H
#define PLANT2_H

class Plant2 {

private:
	string name;
	PlantState* state;
	double price;
	CareStrategy* care;
public:
	int size;
	int id;
	int health;
private:
	PlantData* plantData;

public:
	void grow();

	void accept(CareVisitor& visitor);
};

#endif
