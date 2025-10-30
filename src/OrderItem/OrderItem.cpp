#include "OrderItem.h"
#include <iostream>

OrderItem::OrderItem() {
    name = "Plant Item";
    unitPrice = 150.0;  // Default price
    qty = 1;
}

double OrderItem::subtotal() {
    return unitPrice * qty;
}

int OrderItem::count() {
    return qty;
}

void OrderItem::list(int itemsOut) {
    std::cout << name << " x" << qty << " @ R" << unitPrice << " = R" << subtotal() << std::endl;
}
