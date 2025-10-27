#include "PlantIterator.h"

PlantIterator::PlantIterator(const std::vector<Plant*>& plantsList) : plants(plantsList), curIndex(0) {}

bool PlantIterator::hasNext() {
	return curIndex < plants.size();
}

Plant* PlantIterator::next() { // returns next plant
	if(!hasNext()) {
		return nullptr; // or throw an exception
	}
	return plants[curIndex++];
}

Plant* PlantIterator::first() { // returns first plant
	if(plants.empty()) {
		return nullptr;
	}
	curIndex = 1;
	return plants[0];
}

Plant* PlantIterator::currItem() {
	if(curIndex == 0 || curIndex > plants.size()) {
		return nullptr;
	}
	return plants[curIndex-1];
}
