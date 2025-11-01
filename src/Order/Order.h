/**
 * @file Order.h
 * @brief Order management class for handling customer orders
 * 
 * This file defines the Order class which manages a collection of order items
 * and provides methods to calculate totals, retrieve order information, and
 * work with delivery strategies.
 */

#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <list>

class OrderItem;

/**
 * @class Order
 * @brief Manages a collection of order items for customer purchases
 * 
 * The Order class maintains a list of OrderItem pointers and provides
 * comprehensive order management functionality including:
 * - Adding items to the order
 * - Calculating order totals
 * - Generating formatted order summaries
 * - Counting items in the order
 * - Accessing the item list
 * 
 * The class handles memory management by deleting all OrderItems in its
 * destructor. Works seamlessly with the DeliveryStrategy pattern to
 * enable different delivery methods.
 * 
 * @note Order takes ownership of OrderItem pointers added via addItem()
 * @note All OrderItems are deleted when Order is destroyed
 */
class Order {
private:
    std::list<OrderItem*> items;  ///< List of order items (Order owns these pointers)

public:
    /**
     * @brief Default constructor
     * 
     * Creates an empty order with no items.
     */
    Order();
    
    /**
     * @brief Destructor
     * 
     * Cleans up all dynamically allocated OrderItems in the order.
     * Deletes each item pointer and clears the list.
     * 
     * @note This ensures proper memory management - all items added
     *       to the order are automatically deleted when order is destroyed
     */
    ~Order();
    
    /**
     * @brief Adds an item to the order
     * @param item Pointer to OrderItem to add (Order takes ownership)
     * 
     * Appends the given OrderItem pointer to the order's item list.
     * The Order takes ownership and will delete the item in destructor.
     * 
     * @warning Do not delete the item pointer after passing it to addItem()
     */
    void addItem(OrderItem* item);
    
    /**
     * @brief Calculates the total cost of all items in the order
     * @return Sum of all item subtotals as a double
     * 
     * Iterates through all items and sums their subtotal() values.
     * The subtotal includes item price × quantity, plus any pot decorations.
     * 
     * @note Const method to allow use with const Order references
     * @note Does not include delivery costs - use with DeliveryStrategy
     */
    double total() const;
    
    /**
     * @brief Gets a formatted string representation of the order
     * @return Multi-line string with complete order details
     * 
     * Creates a beautifully formatted order summary including:
     * - "ORDER CONTENTS:" header
     * - Separator lines (===============)
     * - Numbered list of items with:
     *   - Item number
     *   - Item name
     *   - Pot information (if item has a pot)
     *   - Individual item subtotal
     * - Bottom separator line
     * - Order subtotal
     * 
     * Example output:
     * @code
     * ORDER CONTENTS:
     * ===============
     * 1. Rose Plant + Blue pot - R125.0
     * 2. Tulip Plant - R40.0
     * ===============
     * Subtotal: R165.0
     * @endcode
     * 
     * @note Const method to allow use with const Order references
     */
    std::string getOrder() const;
    
    /**
     * @brief Gets the number of items in the order
     * @return Integer count of items in the order
     * 
     * Returns the size of the items list, indicating how many
     * OrderItems have been added to this order.
     * 
     * @note Const method to allow use with const Order references
     */
    int getItemCount() const;
    
    /**
     * @brief Gets read-only access to the items list
     * @return Const reference to the list of OrderItem pointers
     * 
     * Provides direct access to the internal items list for iteration
     * or inspection without allowing modification of the list itself.
     * 
     * @note Returns const reference to prevent external modification
     * @note Useful for iterating over items or accessing item details
     */
    const std::list<OrderItem*>& getItems() const;
};

#endif
