#include "Order.h"
#include "../OrderItem/OrderItem.h"

void Order::addItem(OrderItem* item) {
    items.push_back(item);
}

double Order::total() {
    double sum = 0;
    for (auto it = items.begin(); it != items.end(); ++it) {
        sum += (*it)->subtotal();
    }
    return sum;
}

std::string Order::getOrder() {
    std::string ret = "";
    for (auto it = items.begin(); it != items.end(); ++it) {
        ret += (*it)->name + "\n";
    }
    return ret;
}

Order::Order()
{
}
