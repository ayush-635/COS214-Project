#ifndef CAREFORPLANTCOMMAND_H
#define CAREFORPLANTCOMMAND_H

#include "Duty.h"


/**
 * @class CareForPlantCommand
 * @brief Abstract command for plant care operations (fertilizer, medicine, watering)
 */
class CareForPlantCommand : public Duty {
public:
    
    virtual void executeDuty(PlantableArea* area) = 0;
};

#endif
