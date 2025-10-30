#include "GiveMedicineCommand.h"
#include "../src/PlanterBoxCollection/PlanterBoxCollection.h"
#include <iostream>



GiveMedicineCommand::GiveMedicineCommand(PlanterBoxCollection* collection, int units, int index)
    : CareForPlantCommand(collection, index), units(units) {}


 void GiveMedicineCommand::executeDuty() {

     if (!collection) {
        std::cout << " No plant row assigned.\n";
        return;
    }



    collection->giveMedicine(units, index);
}
