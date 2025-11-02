#include "PlantIterator.h"

PlantIterator::PlantIterator(PlantableArea* rootArea) 
    : plantIndex(0), rootArea(rootArea) {  // FIX: Initialize rootArea member
    if(rootArea != nullptr) {
        areaStack.push(rootArea);
        loadCurrentBoxPlants();
    }
}

PlantIterator::~PlantIterator() {
    while(!areaStack.empty()) {
        areaStack.pop();
    }
    plants.clear();
}

void PlantIterator::loadCurrentBoxPlants() {
    plants.clear();
    plantIndex = 0;

    while(!areaStack.empty()){
        PlantableArea* cur = areaStack.top();

        PlanterBox* box = dynamic_cast<PlanterBox*>(cur);
        if(box != nullptr){
            plants = box->getPlants();
            if(!plants.empty()){
                return; // found plants
            }
            areaStack.pop();
            continue;
        }

        // Try casting to PlanterBoxCollection (composite)
        PlanterBoxCollection* collection = dynamic_cast<PlanterBoxCollection*>(cur);
        if(collection != nullptr) {
            areaStack.pop(); // Remove collection from stack
            
            // FIX: Push all children onto stack (check up to 10, not just 4)
            for(int i = 9; i >= 0; i--) {
                PlantableArea* child = collection->getChild(i);
                if(child != nullptr) {
                    areaStack.push(child);
                }
            }
            continue;
        }

        areaStack.pop(); // Unknown type, skip
    }
}

void PlantIterator::advanceToNextValidBox() {
    if(!areaStack.empty()){
        areaStack.pop();
    }
    loadCurrentBoxPlants();
}

bool PlantIterator::hasNext() {
    if(plantIndex < plants.size()){
        return true;
    }
    return !areaStack.empty(); // see if there are more levels to traverse
}

Plant* PlantIterator::next() {
    if(!hasNext()) {
        return nullptr;
    }

    // Return next plant from current box
    if(plantIndex < plants.size()) {
        return plants[plantIndex++];
    }

    // Current box out of plants move to the next valid box or collection
    advanceToNextValidBox();
    
    if(plantIndex < plants.size()) {
        return plants[plantIndex++];
    }

    return nullptr;
}

Plant* PlantIterator::first() { // returns first plant
    //reset stack
    while(!areaStack.empty()){
        areaStack.pop();
    }

    plantIndex = 0;
    plants.clear();

    // Re-push the root
    if(rootArea != nullptr) {
        areaStack.push(rootArea);
        loadCurrentBoxPlants();
    }

    if(!plants.empty()){
        return plants[plantIndex++];
    }

    return nullptr;
}

Plant* PlantIterator::currItem() {
    if(plantIndex == 0 || plantIndex > plants.size()) {
        return nullptr;
    }
    return plants[plantIndex-1];
}