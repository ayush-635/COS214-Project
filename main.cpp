#include "src/NurseryManager/NurseryManager.h"
#include "src/ConcreteSpaceBuilder/ConcreteSpaceBuilder.h"
#include "src/PlanterBox/PlanterBox.h"
#include "src/PlanterBoxCollection/PlanterBoxCollection.h"

int main() {
NurseryManager manager;
    ConcreteSpaceBuilder* builder = new ConcreteSpaceBuilder();
    manager.setBuilder(builder);
    
    std::cout << "\n=== Building Small Space ===" << std::endl;
    PlantableArea* smallSpace = manager.constructSmallSpace();
    if (smallSpace) {
        smallSpace->display();
    }
    
    std::cout << "\n=== Building Medium Space ===" << std::endl;
    PlantableArea* mediumSpace = manager.constructMediumSpace();
    if (mediumSpace) {
        mediumSpace->display();
    }
    
    std::cout << "\n=== Building Big Space ===" << std::endl;
    PlantableArea* bigSpace = manager.constructBigSpace();
    if (bigSpace) {
        bigSpace->display();
    }
    
    std::cout << "\n=== Using Default Builder Method ===" << std::endl;
    builder->createNewSpace();
    builder->addDefault();
    PlantableArea* defaultSpace = builder->build();
    if (defaultSpace) {
        defaultSpace->display();
    }
    
    // Clean up
    delete builder;
    delete smallSpace;
    delete mediumSpace;
    delete bigSpace;
    delete defaultSpace;
    
    return 0;
}