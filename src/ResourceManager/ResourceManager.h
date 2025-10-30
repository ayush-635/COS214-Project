#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <iostream>
using namespace std;

class WaterStorage;
class FertilizerStorage;

class ResourceManager {
private:
    WaterStorage* waterStorage;
    FertilizerStorage* fertilizerStorage;

public:
    bool useWater(int amt);
    bool useFertilizer(int amt);
    bool refillAll();
    bool upgradeAll();
    
    ResourceManager();
    ~ResourceManager();
};

#endif
