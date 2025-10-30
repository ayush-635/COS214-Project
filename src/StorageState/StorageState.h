#ifndef STORAGESTATE_H
#define STORAGESTATE_H

class StorageState {
public:
//made pure virtual-we dont want to use multiple inheritance here
    virtual ~StorageState() {}
    
    virtual bool upgrade() = 0;
    virtual bool refill() = 0;
};

#endif
