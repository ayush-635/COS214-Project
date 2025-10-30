#ifndef GARDNER_H
#define GARDNER_H

#include "../StaffMember/StaffMember.h"

class Gardner : public StaffMember {
    private:
        std::string currPreference;
    public:
        ~Gardner() override{};

        void tick(int time) override;

        void receivePreference(const std::string& pref) override;

        void browse() override;

        void sendAdvice(const std::string& advice) override;
};

#endif
