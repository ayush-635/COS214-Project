#ifndef WATERSTORAGE_H
#define WATERSTORAGE_H

class StorageState;

class WaterStorage {
private:
    int capacity;
    int level;
    StorageState* state;

public:
    WaterStorage(int cap = 1000);
    ~WaterStorage();
    
    bool use(int amt);
    bool refill();
    bool upgrade();
    
    int getLevel() const { return level; }
    int getCapacity() const { return capacity; }
};

#endif
