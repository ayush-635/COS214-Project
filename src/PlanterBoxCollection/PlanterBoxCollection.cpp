#include "PlanterBoxCollection.h"

PlanterBoxCollection::PlanterBoxCollection(int depth) : depth(depth) {}

void PlanterBoxCollection::add(PlantableArea* area){

    // check to make sure area is valid and not null
	if(area == nullptr){
        std::cout << "Cannot add null PlanterBox." << std::endl;
        return;
    }

    // check that the tile still has space for more boxes/collections
    if(boxes.size() >= max_boxes){
        std::cout << "PlanterBoxCollection has reached maximum capacity of " << max_boxes << " boxes." << std::endl;
        return;
    }

    // cast passed in area to planterBoxCollection to see if its a collection
    PlanterBoxCollection* collectionArea = dynamic_cast<PlanterBoxCollection*>(area);
    if(collectionArea != nullptr){ // it's a collection, so check depth constraints
        // Child's depth should be exactly parent's depth + 1
        if(collectionArea->getDepth() != this->depth + 1){
            std::cout << "Cannot add PlanterBoxCollection. Child must be at depth " << (this->depth + 1) << ", but is at depth " << collectionArea->getDepth() << std::endl;
            return;
        }
        
        // Also check if it exceeds maximum allowed depth
        if(collectionArea->getDepth() > max_depth){
            std::cout << "Cannot add PlanterBoxCollection. Exceeds maximum depth of " << max_depth << "." << std::endl;
            return;
        }
    }

    boxes.push_back(area); // all tests passed, add the area
    std::cout << "Added " << (collectionArea ? "PlanterBoxCollection" : "PlanterBox") << " to collection on level " << this->depth << std::endl;
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
	// Delegate to first available box
    for(auto box : boxes){
        Plant* result = box->removePlant(plant);
        if(result != nullptr) return result;
    }
    return nullptr;
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
