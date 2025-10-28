#include <iostream>
#include <cassert>

//Temp until Plant is complete
struct Plant{};

#include "../src/Observer/Observer.h"
#include "../src/Subject/Subject.h"
#include "../src/InventoryObserver/InventoryObserver.h"
#include "../src/Inventory/Inventory.h"

class FakeInv : public Subject {
    public:
        void changeStock(Plant* p){
            notifyStockChange(p);
        }
};

int main(){
    std::cout << "Running Observer pattern test..." << std::endl;
    FakeInv inv;
    InventoryObserver obs;

    inv.attach(&obs);
    Plant p1;
    Plant p2;
    Plant p3;

    inv.changeStock(&p1);
    inv.changeStock(&p2);
    inv.changeStock(&p3);

    obs.printStock(std::cout);

    Inventory* i1 = Inventory::getInstance();
    Inventory* i2 =Inventory::getInstance();

    assert(i1 != 0);
    assert(i1 == i2);
    std::cout << "Inventory::getInstance() returns singleton at " << i1 << "\n";

    return 0;
}