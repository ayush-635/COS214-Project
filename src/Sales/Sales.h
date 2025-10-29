#ifndef SALES_H
#define SALES_H
#include "../StaffMember/StaffMember.h"
#include <string>
#include "../Inventory/Inventory.h"
#include "../Plant/Plant.h"
#include "../PlantData/PlantData.h"

class Sales : public StaffMember {
    private:
        std::string currPreference;
        std::string findMatchingPlant(bool outside, bool lowLight, bool lowWater, bool brightColour, bool lowCare);
    public:
        void receivePreference(const std::string& pref);
        void sendAdvice(const std::string& advice);
        Sales();
        void browse();
        std::string handlePurchase(int numPlants);
};

#endif
