#ifndef CASHIER_H
#define CASHIER_H

class Cashier : StaffMember {

public:
	InventoryObserver* inventoryObserver;

	boolean checkStockLevel();

	void requestNewStock(Plant* plant);
};

#endif
