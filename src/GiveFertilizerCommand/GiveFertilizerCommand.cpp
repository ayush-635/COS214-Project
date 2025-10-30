#include "../src/GiveFertilizerCommand/GiveFertilizerCommand.h"


GiveFertilizerCommand::GiveFertilizerCommand(PlanterBoxCollection* collection, int units, int index)
    : collection(collection), units(units), index(index) {}


void GiveFertilizerCommand::executeDuty() {

     if (!collection) {
        std::cout << " No plant row assigned.\n";
        return;
    }

    collection->giveFertilizer(units, index); 
}
