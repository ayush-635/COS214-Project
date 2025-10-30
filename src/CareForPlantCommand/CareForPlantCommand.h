#ifndef CAREFORPLANTCOMMAND_H
#define CAREFORPLANTCOMMAND_H

#include "../src/Duty/Duty.h"



class CareForPlantCommand : public Duty {



public:
   

    virtual void executeDuty() = 0;
};

#endif
