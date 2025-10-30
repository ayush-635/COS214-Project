#ifndef SALES_H
#define SALES_H
#include "../StaffMember/StaffMember.h"
#include <string>
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"
#include "../PlantData/PlantData.h"
#include "../Mediator/Mediator.h"
#include "../StaffMember/StaffMember.h"
#include <string>
#include <vector>

class Sales : public StaffMember {
    private:
        std::string currPreference;
        std::string findMatchingPlant(bool outside, bool lowLight, bool lowWater, bool brightColour, bool lowCare);

    public:
        Sales();
        virtual ~Sales(){};

        void tick(int time);

        std::string findMatchingPlant(bool outside, bool lowLight, bool lowWater, bool brightColour, bool lowCare);

        void receivePreference(const std::string& pref);

        void browse();

        void sendAdvice(const std::string& advice);

        std::string handlePurchase(int numPlants);

};

#endif
