#include "../src/GiveMedicineCommand/GiveMedicineCommand.h"


GiveMedicineCommand::GiveMedicineCommand(PlanterBoxCollection* collection, int units, int index)
    : collection(collection), units(units) , index(index){}

 void GiveMedicineCommand::executeDuty() {

     if (!collection) {
        std::cout << " No plant row assigned.\n";
        return;
    }



    collection->giveMedicine(units, index);
}
