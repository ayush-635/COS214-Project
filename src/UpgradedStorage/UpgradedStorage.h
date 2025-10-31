#ifndef UPGRADEDSTORAGE_H
#define UPGRADEDSTORAGE_H

#include "../State/StorageState.h"
#include <string>

class UpgradedStorage : public StorageState {
public:
    std::string refill() override;
    std::string upgrade() override;
};

#endif
