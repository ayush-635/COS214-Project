#include "FertilizerStorage.h"
#include "StorageState.h"
#include "BasicStorage.h"
#include <iostream>
using namespace std;

FertilizerStorage::FertilizerStorage(int cap) {
    capacity = cap;
    level = cap;  // Start full
    state = new BasicStorage();  // Start in basic state
    cout << "FertilizerStorage initialized: " << level << "/" << capacity << " units" << endl;
}

FertilizerStorage::~FertilizerStorage() {
    delete state;
}

bool FertilizerStorage::use(int amt) {
    if (level >= amt) {
        level -= amt;
        cout << "Used " << amt << " units of fertilizer. Remaining: " << level << "/" << capacity << endl;
        return true;
    } else {
        cout << "ERROR: Insufficient fertilizer! Need " << amt << ", have " << level << endl;
        return false;
    }
}

bool FertilizerStorage::refill() {
    if (state != nullptr) {
        bool result = state->refill();
        if (result) {
            level = capacity;
            cout << "Fertilizer storage refilled to " << capacity << " units" << endl;
        }
        return result;
    }
    return false;
}

bool FertilizerStorage::upgrade() {
    if (state != nullptr) {
        bool result = state->upgrade();
        if (result) {
            int upgradeAmount = 250;
            capacity += upgradeAmount;
            level += upgradeAmount;
            cout << "Fertilizer storage upgraded! New capacity: " << capacity << " units" << endl;
        }
        return result;
    }
    return false;
}
