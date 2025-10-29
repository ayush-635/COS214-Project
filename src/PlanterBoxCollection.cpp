#include "PlanterBoxCollection.h"

PlanterBoxCollection::PlanterBoxCollection(int depth) : depth(depth) {}

void PlanterBoxCollection::add(PlantableArea* area){
	if(area == nullptr){
		std::cout << "Cannot add null PlanterBox." << std::endl;
		return;
	}

	if(boxes.size() >= max_boxes){
		std::cout << "PlanterBoxCollection has reached maximum capacity of " << max_boxes << " boxes." << std::endl;
		return;
	}

	PlanterBoxCollection* collectionArea = dynamic_cast<PlanterBoxCollection*>(area);
	if(collectionArea != nullptr && collectionArea->getDepth() + 1 > max_depth){
		std::cout << "Cannot add PlanterBoxCollection. Exceeds maximum depth of " << max_depth << "." << std::endl;
		return;
	}

	boxes.push_back(area);
	std::cout << "Added PlanterBox to collection on level " << depth << std::endl;
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
	if (plantBoxIndex >= 0 && plantBoxIndex < boxes.size()) {
		return boxes[plantBoxIndex]->removePlant(plant);
    } else {
        std::cout << "Invalid PlanterBox index.\n";
		return nullptr;
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

int PlanterBoxCollection::getDepth() const {
	return depth;
}

void PlanterBoxCollection::display() {
	std::cout << "PlanterBoxCollection at depth " << depth << " contains " << boxes.size() << " boxes." << std::endl;
	for (size_t i = 0; i < boxes.size(); ++i) {
		std::cout << " Box " << i + 1 << ":" << std::endl;
		boxes[i]->display();
	}
}