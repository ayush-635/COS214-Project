#include "GiveFertilizerCommand.h"


GiveFertilizerCommand::GiveFertilizerCommand(PlanterBoxCollection* collection, int units, int index)
{
    this->collection = collection;
    this->units = units;
    this->index = index;
 }


void GiveFertilizerCommand::executeDuty() {

     if (!collection) {
        std::cout << " No plant row assigned.\n";
        return;
    }

    collection->giveFertilizer(units, index); 
}
