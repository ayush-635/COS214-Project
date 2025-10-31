#include "OrderItem.h"
#include <string>
#include <sstream>

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

string OrderItem::list(int itemsOut) {
    std::ostringstream oss;
    oss << name << " x" << qty << " @ R" << unitPrice << " = R" << subtotal();
    return oss.str();
}
