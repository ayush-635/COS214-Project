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
	for(size_t i = 0; i < plants.size(); i++){
		if(plants[i]->getName() == plant->getName()){
			Plant* removed = plants[i];
			plants.erase(plants.begin() + i);
			std::cout << "Removed " << removed->getName() << " from planter box" << std::endl; 
			return removed; // plant removed returned to be added to store/inventory
		}
	}
	return nullptr;
}

void PlanterBox::water(int unit) {
	
}

void PlanterBox::giveMedicine() {
	
}
