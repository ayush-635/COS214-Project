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
	std::vector<PlantableArea*>::iterator it;

	for(it = boxes.begin(); it != boxes.end(); it++){
		if(*it == area){
			boxes.erase(it);
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

	std::vector<PlantableArea*>::iterator it;

	for(it = boxes.begin(); it != boxes.end(); it++){
		if(*it != nullptr){
			(*it)->populate(plant);
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
	//TODO: need to find a way to maybe use state of a plant stored to automatically pick the first one thats ready for harvest
	
}

Plant* PlanterBoxCollection::removePlant(Plant* plant, int plantBoxIndex){
	//TODO:
	if (plantBoxIndex >= 0 && plantBoxIndex < boxes.size()) {
        boxes[plantBoxIndex]->removePlant(plant);
    } else {
        std::cout << "Invalid PlanterBox index.\n";
    }
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