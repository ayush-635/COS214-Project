#include "UpgradedStorage.h"
#include <string>
using namespace std;

string UpgradedStorage::refill() {
    return "[UpgradedStorage] Refilling upgraded storage (faster)...";
}

string UpgradedStorage::upgrade() {
    return "[UpgradedStorage] Already at maximum upgrade level!";
}
