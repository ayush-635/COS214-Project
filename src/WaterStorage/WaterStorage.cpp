#include "WaterStorage.h"
#include "../State/StorageState.h"
#include "../State/BasicStorage.h"

WaterStorage::WaterStorage(int cap) {
    capacity = cap;
    level = cap;  // Start full
    state = new BasicStorage();  // Start in basic state
}

WaterStorage::~WaterStorage() {
    delete state;
}

bool WaterStorage::use(int amt) {
    if (level >= amt) {
        level -= amt;
        return true;
    } else {
        return false;
    }
}

bool WaterStorage::refill() {
    if (state != nullptr) {
        bool result = state->refill();
        if (result) {
            level = capacity;
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
        }
        return result;
    }
    return false;
}
