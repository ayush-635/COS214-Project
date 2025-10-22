#ifndef PLANTDATA_H
#define PLANTDATA_H

class PlantData {

private:
	string speciesName;
	string texturePath;
	double basePrice;
	int wateringNeed;
	int fertilizerNeed;
	double growthRate;

public:
	void displaySharedInfo();
};

#endif
