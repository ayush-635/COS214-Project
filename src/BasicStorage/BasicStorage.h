#ifndef BASICSTORAGE_H
#define BASICSTORAGE_H

#include "StorageState.h"

class BasicStorage : public StorageState {
public:
    bool refill() override;
    bool upgrade() override;
};

#endif
