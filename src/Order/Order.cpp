/**
 * @file Order.cpp
 * @brief Implementation of Order class
 */

#include "Order.h"
#include "../OrderItem/OrderItem.h"
#include <sstream>

/**
 * @brief Default constructor implementation
 * 
 * Creates an empty order with an empty items list.
 * No initialization needed as list initializes itself.
 */
Order::Order() {
}

/**
 * @brief Destructor implementation
 * 
 * Performs cleanup of all dynamically allocated OrderItems.
 * Iterates through the items list and deletes each OrderItem pointer,
 * then clears the list. This ensures no memory leaks.
 * 
 * @note Uses range-based for loop for clean iteration
 */
Order::~Order() {
    for (auto item : items) {
        delete item;
    }
    items.clear();
}

/**
 * @brief Adds an item to the order
 * 
 * Appends the OrderItem pointer to the end of the items list.
 * Order takes ownership of the pointer.
 * 
 * @param item Pointer to OrderItem to add to the order
 */
void Order::addItem(OrderItem* item) {
    items.push_back(item);
}

/**
 * @brief Calculates order total
 * 
 * Sums the subtotal() of all OrderItems in the order.
 * Each item's subtotal includes its base price × quantity,
 * plus any pot decoration costs.
 * 
 * @return Total cost of all items as a double
 */
double Order::total() const {
    double sum = 0;
    for (auto item : items) {
        sum += item->subtotal();
    }
    return sum;
}

/**
 * @brief Generates formatted order string
 * 
 * Creates a detailed, multi-line string representation of the order
 * using a stringstream for efficient string building.
 * 
 * The format includes:
 * - Header: "ORDER CONTENTS:"
 * - Top separator: "==============="
 * - Item list: Each item numbered with name, optional pot, and price
 * - Bottom separator: "==============="
 * - Total: "Subtotal: R[amount]"
 * 
 * For each item:
 * - Shows item number (1-based indexing)
 * - Shows item name
 * - If item has a pot, shows pot color
 * - Shows individual item subtotal with R prefix
 * 
 * @return Formatted order string with all details
 * 
 * @note Uses stringstream for efficient string concatenation
 * @note Checks hasPot() before accessing pot details
 */
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

/**
 * @brief Returns the number of items in order
 * 
 * @return Size of items list as integer
 */
int Order::getItemCount() const {
    return items.size();
}

/**
 * @brief Provides read-only access to items
 * 
 * Returns a const reference to the internal items list,
 * allowing external code to iterate over or inspect items
 * without being able to modify the list structure.
 * 
 * @return Const reference to the list of OrderItem pointers
 */
const std::list<OrderItem*>& Order::getItems() const {
    return items;
}
