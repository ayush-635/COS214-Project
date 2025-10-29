#ifndef PLANTDATA_H
#define PLANTDATA_H
#include <string>

class PlantData {

private:
	std::string speciesName;
	std::string texturePath;
	double basePrice;
	int wateringNeed;
	int fertilizerNeed;
	double growthRate;
	bool outside;
	bool lowLight;
	bool lowWater;
	bool brightColour;
	bool lowCare;

public:
	void displaySharedInfo();
};

#endif
