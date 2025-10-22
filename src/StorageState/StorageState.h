#ifndef STORAGESTATE_H
#define STORAGESTATE_H

class StorageState : FertilizerStorage, WaterStorage {


public:
	bool upgrade();

	bool refill();
};

#endif
