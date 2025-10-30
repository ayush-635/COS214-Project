#ifndef PATHOLOGIST_H
#define PATHOLOGIST_H

#include "../StaffMember/StaffMember.h"

class Pathologist : public StaffMember {
    private:
        std::string currPreference;
    public:
        void tick(int time) override;

        void browse() override {}

        void receivePreference(const std::string& pref) override;
        
        void sendAdvice(const std::string& advice) override;
};

#endif
