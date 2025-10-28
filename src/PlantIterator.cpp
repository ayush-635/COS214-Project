#include "PlantIterator.h"

PlantIterator::PlantIterator(const std::vector<PlantableArea*>& plantsList) : boxIndex(0), plantIndex(0), boxes(plantsList){
	if(boxes.empty()) {
		return;
	}
}

bool PlantIterator::hasNext() {
	// Check if current box has more plants
	if(plantIndex < plants.size()) {
		return true;
	}

	// Check if there are more boxes with plants if there are no more plants in current box
	for(size_t i = boxIndex + 1; i < boxes.size(); i++){
		if(boxes[i] != nullptr){
			PlanterBox* box = dynamic_cast<PlanterBox*>(boxes[i]);
			if(box != nullptr && !box->getPlants().empty()){
				return true;
			}
		}
	}

	return false;
}

void PlantIterator::loadCurrentBoxPlants() {
	plants.clear();
	plantIndex = 0;

	if (boxIndex < boxes.size() && boxes[boxIndex] != nullptr) {
		PlanterBox* box = dynamic_cast<PlanterBox*>(boxes[boxIndex]);
		if (box != nullptr) {
			plants = box->getPlants();
		}
	}
}

void PlantIterator::advanceToNextValidBox() {
    boxIndex++;
	while(boxIndex < boxes.size()) {
		if(boxes[boxIndex] != nullptr){
			loadCurrentBoxPlants();
			if(!plants.empty()){
				return;
			}
		}
		boxIndex++;
	}
    plants.clear();
}

Plant* PlantIterator::next() { // returns next plant
	if(!hasNext()) {
		return nullptr; // or throw an exception
	}
	
	// If current box out of plants, move to next box
    if (plantIndex >= plants.size()) {
        advanceToNextValidBox();
    }

    if (boxIndex < boxes.size() && plantIndex < plants.size()) {
        return plants[plantIndex++];
    }
    return nullptr;
}

Plant* PlantIterator::first() { // returns first plant
	boxIndex = 0;
	plantIndex = 0;
	if(!boxes.empty()){
		loadCurrentBoxPlants();
		if(!plants.empty()){
			return plants[plantIndex++];
		}
	}
	return nullptr;
}

Plant* PlantIterator::currItem() {
	if(boxIndex >= boxes.size() || plantIndex == 0 || plantIndex > plants.size()) {
		return nullptr;
	}
	return plants[plantIndex-1];
}
