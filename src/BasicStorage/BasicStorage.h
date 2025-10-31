#ifndef BASICSTORAGE_H
#define BASICSTORAGE_H

#include "../State/StorageState.h"
#include <string>

class BasicStorage : public StorageState {
public:
    std::string refill() override;
    std::string upgrade() override;
};

#endif
