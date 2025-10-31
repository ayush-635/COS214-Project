#include "UpgradedStorage.h"

bool UpgradedStorage::refill() {
    // Upgraded storage refills faster/more efficiently
    return true;
}

bool UpgradedStorage::upgrade() {
    // Already upgraded - cannot upgrade further
    return false;
}
