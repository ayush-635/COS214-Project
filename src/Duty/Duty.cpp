
#include "Duty.h"

#include "../PlanterBoxCollection/PlanterBoxCollection.h"

Duty::Duty(PlanterBoxCollection* collection, int index)
        : collection(collection), index(index) {}


Duty::~Duty() {}
