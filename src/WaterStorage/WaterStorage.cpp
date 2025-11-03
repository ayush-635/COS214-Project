/* #include "WaterStorage.h"
#include <iostream>
using namespace std;

WaterStorage::WaterStorage(int cap) {
    capacity = cap;
    level = cap;  // Start full
    state = new BasicStorage();  // Start in basic state
    cout << "WaterStorage initialized: " << level << "/" << capacity << " units" << endl;
}

WaterStorage::~WaterStorage() {
    delete state;
}

bool WaterStorage::use(int amt) {
    if (level >= amt) {
        level -= amt;
        cout << "Used " << amt << " units of water. Remaining: " << level << "/" << capacity << endl;
        return true;
    } else {
        cout << "ERROR: Insufficient water! Need " << amt << ", have " << level << endl;
        return false;
    }
}

bool WaterStorage::refill() {
    if (state != nullptr) {
        bool result = state->refill();
        if (result) {
            level = capacity;
            cout << "Water storage refilled to " << capacity << " units" << endl;
        }
        return result;
    }
    return false;
}

bool WaterStorage::upgrade() {
    if (state != nullptr) {
        bool result = state->upgrade();
        if (result) {
            int upgradeAmount = 500;
            capacity += upgradeAmount;
            level += upgradeAmount;
            cout << "Water storage upgraded! New capacity: " << capacity << " units" << endl;
        }
        return result;
    }
    return false;
}
 */