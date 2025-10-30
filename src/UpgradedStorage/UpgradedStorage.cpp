#include "UpgradedStorage.h"
#include <iostream>
using namespace std;

bool UpgradedStorage::refill() {
    cout << "[UpgradedStorage] Refilling upgraded storage (faster)..." << endl;
    // Upgraded storage refills faster/more efficiently
    return true;
}

bool UpgradedStorage::upgrade() {
    cout << "[UpgradedStorage] Already at maximum upgrade level!" << endl;
    // Already upgraded - cannot upgrade further
    return false;
}
