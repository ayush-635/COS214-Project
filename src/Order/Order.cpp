#include "Order.h"
#include "OrderItem.h"
#include <list>
#include <string>
#include <iostream>

Order::Order() {
    delivery = nullptr;
}

void Order::addItem() {
    // to add a new item to the order
    OrderItem* newItem = new OrderItem();
    items.push_back(newItem);
}

double Order::total() {
    // in order to calculate total of all items in the order
    double sum = 0.0;
    for (OrderItem* item : items) {
        sum += item->subtotal();
    }
    return sum;
}
