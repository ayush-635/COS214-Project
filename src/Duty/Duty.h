/**

* @file Duty.h
* @brief Abstract base class representing a staff duty in the plant garden.
  */

#ifndef DUTY_H
#define DUTY_H

#include "../PlanterBoxCollection/PlanterBoxCollection.h"

/**

* @class Duty
* @brief Abstract base class for all duties that a staff member can perform.
*
* Each duty operates on a PlanterBoxCollection and has an associated index
* indicating a specific row or planter box within the collection.
  */
  class Duty {
  protected:
  PlanterBoxCollection* collection; /**< Pointer to the collection this duty operates on */
  int index;                        /**< Index of the planter row/box in the collection */

public:
/**
* @brief Constructs a Duty.
* @param collection Pointer to the PlanterBoxCollection this duty will operate on.
* @param index The index within the collection where the duty is applied.
*/
Duty(PlanterBoxCollection* collection, int index);

```
/**
 * @brief Virtual destructor.
 */
virtual ~Duty();

/**
 * @brief Executes the specific duty.
 *
 * This is a pure virtual method that must be implemented by derived classes.
 */
virtual void executeDuty() = 0;
```

};

#endif
