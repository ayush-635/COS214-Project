#include "Order.h"
#include "../OrderItem/OrderItem.h"
#include <sstream>

Order::Order() {
}

Order::~Order() {
    items.clear();
}

void Order::addItem(OrderItem* item) {
    items.push_back(item);
}

double Order::total() const {
    double sum = 0;
    for (auto item : items) {
        sum += item->subtotal();
    }
    return sum;
}

std::string Order::getOrder() const {
    std::stringstream ss;
    ss << "ORDER CONTENTS:\n";
    ss << "===============\n";
    int itemNum = 1;
    for (auto item : items) {
        ss << itemNum++ << ". " << item->name;
        if (item->hasPot()) {
            ss << " + " << item->getPot()->getColour() << " pot";
        }
        ss << " - R" << item->subtotal() << "\n";
    }
    ss << "===============\n";
    ss << "Subtotal: R" << total() << "\n";
    return ss.str();
}

int Order::getItemCount() const {
    return items.size();
}

const std::list<OrderItem*>& Order::getItems() const {
    return items;
}