
#ifndef PLANTDATA_H
#define PLANTDATA_H
#include <string>

class PlantData {
private:
	std::string speciesName;
	double basePrice;
	int wateringNeed;
	int fertilizerNeed;
	double growthRate;
	bool outside;
	bool lowLight;
	bool lowWater;
	bool brightColour;
	bool lowCare;
    int waterNeededForNextState;
    int fertilizerNeededForNextState;
    int waterInterval;
    int fertilizerInterval;
    int waterDeathTime;
    int fertilizerDeathTime;

public:
    PlantData(const std::string& name, int waterForState, int fertilizerForState,
              int waterInt, int fertilizerInt, int waterDeath, int fertilizerDeath);
    
    PlantData(const PlantData& other);

    std::string getSpeciesName() const { return speciesName; }
    int getWaterNeededForNextState() const { return waterNeededForNextState; }
    int getFertilizerNeededForNextState() const { return fertilizerNeededForNextState; }
    int getWaterInterval() const { return waterInterval; }
    int getFertilizerInterval() const { return fertilizerInterval; }
    int getWaterDeathTime() const { return waterDeathTime; }
    int getFertilizerDeathTime() const { return fertilizerDeathTime; }
    bool isOutside() const { return outside; }
    bool isLowLight() const { return lowLight; }
    bool isLowWater() const { return lowWater; }
    bool isBrightColour() const { return brightColour; }
    bool isLowCare() const { return lowCare; }
    PlantData* getPlantData(){return this;};
};

#endif