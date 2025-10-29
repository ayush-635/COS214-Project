#include "PlantData.h"

PlantData::PlantData(const std::string& name, int waterForState, int fertilizerForState,
                     int waterInt, int fertilizerInt, int waterDeath, int fertilizerDeath)
    : speciesName(name), waterNeededForNextState(waterForState), 
      fertilizerNeededForNextState(fertilizerForState), waterInterval(waterInt),
      fertilizerInterval(fertilizerInt), waterDeathTime(waterDeath), 
      fertilizerDeathTime(fertilizerDeath) {}
  
PlantData::PlantData(const PlantData& other) {
    speciesName = other.speciesName;
    waterNeededForNextState = other.waterNeededForNextState;
    fertilizerNeededForNextState = other.fertilizerNeededForNextState;
    waterInterval = other.waterInterval;
    fertilizerInterval = other.fertilizerInterval;
    waterDeathTime = other.waterDeathTime;
    fertilizerDeathTime = other.fertilizerDeathTime;
}