#include "Pathologist.h"
#include <iostream>

void Pathologist::tick(int time) {
    std::cout << "Pathologist tick +" << time << " Ticks spent alive: " << totalTime() <<std::endl;
}

void Pathologist::receivePreference(const std::string& pref) {
    currPreference = pref;

    if(pref.find("disease") != std::string::npos){
        sendAdvice("Pathologist: The plant shows signs of disease. Recommend treatment.");
    } else {
        sendAdvice("Pathologist: The plant appears healthy.");
    }
}

void Pathologist::sendAdvice(const std::string& advice) {
    if(mediator){
        mediator->notify(this, advice);
    }
}
