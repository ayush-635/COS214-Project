#ifndef UPGRADEDSTORAGE_H
#define UPGRADEDSTORAGE_H

#include "StorageState.h"

class UpgradedStorage : public StorageState {
public:
    bool refill() override;
    bool upgrade() override;
};

#endif
