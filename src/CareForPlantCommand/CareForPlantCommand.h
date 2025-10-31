#ifndef CAREFORPLANTCOMMAND_H
#define CAREFORPLANTCOMMAND_H

#include "../Duty/Duty.h"

class CareForPlantCommand : public Duty {
public:
   
    CareForPlantCommand();
    virtual void executeDuty() = 0;
};

#endif
