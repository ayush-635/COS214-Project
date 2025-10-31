#include "FertilizerStorage.h"
#include "../State/StorageState.h"
#include "../State/BasicStorage.h"

FertilizerStorage::FertilizerStorage(int cap) {
    capacity = cap;
    level = cap;  // Start full
    state = new BasicStorage();  // Start in basic state
}

FertilizerStorage::~FertilizerStorage() {
    delete state;
}

bool FertilizerStorage::use(int amt) {
    if (level >= amt) {
        level -= amt;
        return true;
    } else {
        return false;
    }
}

bool FertilizerStorage::refill() {
    if (state != nullptr) {
        bool result = state->refill();
        if (result) {
            level = capacity;
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
        }
        return result;
    }
    return false;
}
