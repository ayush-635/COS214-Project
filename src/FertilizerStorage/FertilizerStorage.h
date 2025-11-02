/* #ifndef FERTILIZERSTORAGE_H
#define FERTILIZERSTORAGE_H

class FertilizerStorage {
private:
    int capacity;
    int level;

public:
    FertilizerStorage(int cap = 500);
    ~FertilizerStorage();
    
    bool use(int amt);
    bool refill();
    bool upgrade();
    
    int getLevel() const { return level; }
    int getCapacity() const { return capacity; }
};

#endif
 */