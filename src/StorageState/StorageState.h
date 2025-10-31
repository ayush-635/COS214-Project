#ifndef STORAGESTATE_H
#define STORAGESTATE_H

#include <string>

class StorageState {
public:
//made pure virtual-we dont want to use multiple inheritance here
    virtual ~StorageState() {}
    
    virtual std::string upgrade() = 0;
    virtual std::string refill() = 0;
};

#endif
