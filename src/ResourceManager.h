#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

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
};

#endif
