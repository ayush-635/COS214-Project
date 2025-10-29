#include "BasicStorage.h"
#include <iostream>
using namespace std;

bool BasicStorage::refill() {
    cout << "[BasicStorage] Refilling storage..." << endl;
    // Basic storage can always be refilled
    return true;
}

bool BasicStorage::upgrade() {
    cout << "[BasicStorage] Upgrading to enhanced capacity..." << endl;
    // Basic storage can be upgraded
    return true;
}
