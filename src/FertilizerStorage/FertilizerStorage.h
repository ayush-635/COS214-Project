#ifndef FERTILIZERSTORAGE_H
#define FERTILIZERSTORAGE_H

class FertilizerStorage : ResourceManager {

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
