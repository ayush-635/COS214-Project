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

void PlanterBox::add(PlantableArea* area){
	return;
}

void PlanterBox::remove(PlantableArea* area){
	return;
}

PlantableArea* PlanterBox::getChild(int index){
	return nullptr;
}

void PlanterBox::display() {
	std::cout << "PlanterBox contains " << plants.size() << "/" << max_plant_capacity << " plants." << std::endl;
	std::cout << "Plants in PlanterBox:" << std::endl;
	for(const auto& plant : plants) {
		std::cout << "- " << plant->getName() << std::endl;
	}
}

void PlanterBox::water(int unit, int index) {
	//TODO: Needs an attribute to change in plant
	for (auto it = plants.begin(); it != plants.end(); ++it) {
		for(int i = 0; i<unit; i++){
			(*it)->water();
		}
	}
}

void PlanterBox::giveMedicine(int units, int index) {
	//TODO: Needs an attribute to change in plant
}

void PlanterBox::giveFertilizer(int units, int index){
	//TODO: Needs an attribute to change in plant
		for (auto it = plants.begin(); it != plants.end(); ++it) {
		for(int i = 0; i<units; i++){
			(*it)->fertilize();
		}
	}
}
