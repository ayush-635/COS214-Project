/**
 * @file Order.h
 * @brief Header file for the Order class
 */

#ifndef ORDER_H
#define ORDER_H
#include <string>
#include <list>

class OrderItem;

/**
 * @class Order
 * @brief Represents a customer order containing multiple order items
 */
class Order {
private:
    std::list<OrderItem*> items; /**< List of order items in the order */

public:
    /**
     * @brief Default constructor
     */
    Order();
    
    /**
     * @brief Destructor
     */
    ~Order();
    
    /**
     * @brief Add an item to the order
     * @param item Pointer to the order item to add
     */
    void addItem(OrderItem* item);
    
    /**
     * @brief Calculate the total cost of the order
     * @return Total cost as double
     */
    double total() const;
    
    /**
     * @brief Get order details as string
     * @return String representation of the order
     */
    std::string getOrder() const;
    
    /**
     * @brief Get the number of items in the order
     * @return Item count
     */
    int getItemCount() const;
    
    /**
     * @brief Get all items in the order
     * @return Constant reference to the list of order items
     */
    const std::list<OrderItem*>& getItems() const;
};

#endif