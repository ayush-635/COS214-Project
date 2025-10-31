#ifndef UPGRADEDSTORAGE_H
#define UPGRADEDSTORAGE_H

#include "../State/StorageState.h"

class UpgradedStorage : public StorageState {
public:
    bool refill() override;
    bool upgrade() override;
};

#endif
