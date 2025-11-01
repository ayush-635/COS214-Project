#include <iostream>
#include <cassert>

#include "../src/Observer/Observer.h"
#include "../src/Subject/Subject.h"
#include "../src/InventoryObserver/InventoryObserver.h"
#include "../src/Inventory/Inventory.h"
#include "../src/PlantFactory/PlantFactory.h"
#include "../src/Plant/Plant.h"
#include "../src/PlantData/PlantData.h"

class TestPlantData : public PlantData {
public:
    explicit TestPlantData(const std::string& species)
    : PlantData(
        species,
        1,
        1,
        3,
        3,
        7,
        7
    ) {}
    virtual ~TestPlantData() {}
};

class TestPlant : public Plant {
public:
    explicit TestPlant(const std::string& name)
    : Plant(name + "_id", name, std::shared_ptr<PlantData>(new TestPlantData(name))) {}

    virtual Plant* clone() { return new TestPlant(*this); }
    virtual void accept(CareVisitor&) {}
};

class TestFactory : public PlantFactory {
public:
    virtual ~TestFactory() {}
    virtual Plant* createPlant(std::string name) {
        return new TestPlant(name);
    }
};

int main(){
    std::cout << "Test Started: \n\n";
    TestFactory factory;
    Plant* tmp = new TestPlant("Rose");
    factory.addPlantPrototype(tmp);
    delete tmp;
    tmp = new TestPlant("Lily");
    delete tmp;

    Inventory* inv = Inventory::getInstance();
    inv->setFactory(&factory);

    InventoryObserver obs;
    inv->attach(&obs);

    inv->addStockType(&factory, "Rose", "Spring");
    inv->addStockType(&factory, "Rose", "Fall");
    inv->addStockType(&factory, "Lily", "Summer");
    std::cout << "Ideal season for roses are:" << inv->getIdealSeason("Rose") << "\n";

    std::cout << "Initial stock — Rose: " << inv->getStock("Rose") << ", Lily: " << inv->getStock("Lily") << "\n";
    inv->restock("Rose", 5);
    inv->restock("Lily", 3);
    std::cout << "Initial stock — Rose: " << inv->getStock("Rose") << ", Lily: " << inv->getStock("Lily") << "\n";

    bool sold = inv->trySell("Rose", 99);
    std::cout << "Attempt oversell Rose by 99: " << (sold? "SUCCESS" : "FAIL") << "\n";
    assert(!sold);
    std::cout << "Stock after failed oversell — Rose: " << inv->getStock("Rose") << "\n";

    sold = inv->trySell("Rose", 2);
    std::cout << "Sell Rose x2 -> " << (sold ? "SUCCESS" : "FAIL") << "\n";
    assert(sold);
    std::cout << "After sale — Rose: " << inv->getStock("Rose") << ", Lily: " << inv->getStock("Lily") << "\n";

    std::cout << "\nObserver snapshot:\n";
    obs.printStock(std::cout);

    Inventory* again = Inventory::getInstance();
    assert(again == inv);

    std::cout << "Testing concluded\n";
    return 0;
}