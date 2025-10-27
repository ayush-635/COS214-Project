#include "PlanterBoxCollection.h"

void PlanterBoxCollection::add(PlantableArea* area){
	if(area != nullptr){
		if(boxes.size() < 4){
			boxes.push_back(area);
		}else{
			std::cout << "Cannot add more PlanterBoxes to the collection. Maximum capacity of 4 has been reached." << std::endl;
		}
		
	}
}

void PlanterBoxCollection::remove(PlantableArea* area){
	for(size_t i = 0; i < boxes.size(); i++){
		if(boxes[i] == area){
			boxes.erase(boxes.begin() + i);
			std::cout << "Removed PlanterBox from collection." << std::endl;
			return;
		}
	}
	std::cout << "PlanterBox not found in collection." << std::endl;
}

PlantableArea* PlanterBoxCollection::getChild(int index){
	if(index < 0 || index >= boxes.size()){ // make sure index in bounds
		return nullptr;
	}
	return boxes[index];
}

void PlanterBoxCollection::populate(Plant* plant){
	for(size_t i = 0; i < boxes.size(); i++){
		if(boxes[i] != nullptr){
			boxes[i]->populate(plant);
			return;
		}
	}
	std::cout << "No available PlanterBox to populate.\n";
}

void PlanterBoxCollection::populate(Plant* plant, int plantBoxIndex){
	if (plantBoxIndex >= 0 && plantBoxIndex < boxes.size()) {
        boxes[plantBoxIndex]->populate(plant);
    } else {
        std::cout << "Invalid PlanterBox index.\n";
    }
}

Plant* PlanterBoxCollection::removePlant(Plant* plant){
	//TODO:
}

Plant* PlanterBoxCollection::removePlant(Plant* plant, int plantBoxIndex){
	//TODO:
}

void PlanterBoxCollection::water(int units){
	//TODO: Needs an attribute to change in plant
}

void PlanterBoxCollection::giveMedicine(int units){
	//TODO: Needs an attribute to change in plant
}

void PlanterBoxCollection::giveFertilizer(int units){
	//TODO: Needs an attribute to change in plant
}