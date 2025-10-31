#ifndef NURSERYMANAGER_H
#define NURSERYMANAGER_H
#include "../SpaceBuilder/SpaceBuilder.h"
#include "../PlantableArea/PlantableArea.h"

class NurseryManager {

private:
	SpaceBuilder* builder;

public:
	NurseryManager() : builder(nullptr){}

	void setBuilder(SpaceBuilder* b){
		builder =b;
	}

	PlantableArea* constructSmallSpace();
	PlantableArea* constructMediumSpace();
	PlantableArea* constructBigSpace();
};

#endif

