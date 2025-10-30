#include "Gardner.h"
#include <iostream>

void Gardner::tick(int time) {
    std::cout << "Gardner tick +" << time << " Ticks spent alive: " << TimeSpent <<std::endl;
}

void Gardner::receivePreference(const std::string& pref) {
    currPreference = pref;
    browse();
}

void Gardner::browse() {
	if (currPreference.empty()) {
		return;
	}
	
	bool needsOutside = (currPreference.find("outside") != std::string::npos);
	bool needsLowLight = (currPreference.find("without much sunlight") != std::string::npos);
	bool needsLowWater = (currPreference.find("not need much water") != std::string::npos);
	bool needsBrightColor = (currPreference.find("bright coloured") != std::string::npos);
	bool needsLowCare = (currPreference.find("not need much attention") != std::string::npos);

    std::string advice =  findMatchingPlant(needsOutside, needsLowLight, needsLowWater, needsBrightColor, needsLowCare);
    sendAdvice(advice);
}

void Gardner::sendAdvice(const std::string& advice) {
    if(mediator){
        mediator->notify(this, advice);
    }
}
