#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H
#include "../Colleague/Colleague.h"
#include "../Colleague/Colleague.h"
#include "../Duty/Duty.h"
#include "../PlantableArea/PlantableArea.h"

class StaffMember : public Colleague {

	protected:
    void addTime(int time);
    int TimeSpent;          
    

public:
    StaffMember();
    virtual ~StaffMember();

    void doDuty();
    void doDuty(int time);

    virtual void tick(int time);

    virtual void receivePreference(const std::string& pref);

    virtual void browse();
	
    virtual void sendAdvice(const std::string& advice);

    int totalTime() const;
};

#endif
