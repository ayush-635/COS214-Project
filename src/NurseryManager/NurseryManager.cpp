#include "NurseryManager.h"

PlantableArea* NurseryManager::constructSmallSpace() {
	if (builder == nullptr) {
        std::cout << "Error: No builder set!" << std::endl;
        return nullptr;
    }
    
    std::cout << "Constructing small space..." << std::endl;
    
    // Small space 2 planter boxes
    builder->createNewSpace();
    builder->addPlanterBox();
    builder->addPlanterBox();
    
    return builder->build();
}

PlantableArea* NurseryManager::constructMediumSpace() {
    if (builder == nullptr) {
        std::cout << "Error: No builder set!" << std::endl;
        return nullptr;
    }
    
    std::cout << "Constructing medium space..." << std::endl;
    
    // Medium space 4 planter boxes
    builder->createNewSpace();
    builder->addPlanterBox();
    builder->addPlanterBox();
    builder->addPlanterBox();
    builder->addPlanterBox();
    
    return builder->build();
}

PlantableArea* NurseryManager::constructBigSpace() {
    if (builder == nullptr) {
        std::cout << "Error: No builder set!" << std::endl;
        return nullptr;
    }
    
    std::cout << "Constructing big space..." << std::endl;
    
    // Big space: Uses nested collections
    builder->createNewSpace();
    
    builder->addSubCollection();
    builder->addPlanterBox();
    builder->addPlanterBox();
    builder->addPlanterBox();
    
    return builder->build();
}

