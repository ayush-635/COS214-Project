#include "PlanterBox.h"

void PlanterBox::populate(Plant* plant) {
	if(plants.size() < max_plant_capacity) {
		plants.push_back(plant);
		std::cout << "Added " << plant->getName() << " to PlanterBox." << std::endl;
	}else{
		std::cout << "PlanterBox has reached capacity create a new one!" << std::endl;
	}
}

Plant* PlanterBox::removePlant(Plant* plant) {
	std::vector<Plant*>::iterator it;

	for(it = plants.begin(); it != plants.end(); it++){
		if(*it == plant){
			Plant* removed = *it;
			plants.erase(it);
			std::cout << "Removed " << removed->getName() << " from planter box" << std::endl;
			return removed; // plant removed returned to be added to store/inventory
		}
	}

	return nullptr;
}

const std::vector<Plant*> PlanterBox::getPlants() {
	return plants;
}

void PlanterBox::water(int unit) {
	//TODO: Needs an attribute to change in plant
}

void PlanterBox::giveMedicine(int units) {
	//TODO: Needs an attribute to change in plant
}

void PlanterBox::giveFertilizer(int units){
	//TODO: Needs an attribute to change in plant
}
