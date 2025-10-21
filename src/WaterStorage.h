#ifndef WATERSTORAGE_H
#define WATERSTORAGE_H

class WaterStorage : ResourceManager {

private:
	int capacity;
	int level;
	StorageState* state;

public:
	bool use(int amt);

	bool refill();

	bool upgrade();
};

#endif
