#ifndef SALES_H
#define SALES_H

#include "../StaffMember/StaffMember.h"

class Sales : public StaffMember {
    private:
        std::string currPreference;

    public:
        Sales();
        virtual ~Sales(){};

        void tick(int time) override;

        std::string findMatchingPlant(bool outside, bool lowLight, bool lowWater, bool brightColour, bool lowCare);

        void receivePreference(const std::string& pref) override;

        void browse() override;

        void sendAdvice(const std::string& advice) override;

        std::string handlePurchase(int numPlants);

};

#endif
