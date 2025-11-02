/**
 * @file OrderItem.h
 * @brief Order item class representing individual products in an order
 * @author Zaynab Samir
 * 
 * This file defines the OrderItem class which represents a single product
 * in an order with quantity, pricing, and optional pot decoration.
 */
#ifndef ORDERITEM_H
#define ORDERITEM_H
#include <string>
#include <sstream>
#include "../Pot/Pot.h"

/**
 * @class OrderItem
 * @brief Represents an individual item in a customer order
 * 
 * OrderItem encapsulates a product with its name, unit price, quantity,
 * and an optional pot decoration. The class manages:
 * - Product information (name, price, quantity)
 * - Optional pot decoration with automatic memory management
 * - Subtotal calculation including pot price
 * - Formatted information display
 * 
 * The pot decoration can be added randomly from a selection of 5 pot types
 * with different colors and prices. The OrderItem owns the pot pointer
 * and handles its memory cleanup in the destructor.
 * 
 * @note OrderItem manages pot memory - pot is deleted in destructor
 * @note Pot price is automatically included in subtotal calculation
 */
class OrderItem {
private:
    double unitPrice;///< Price per single unit of the item
    int qty;///< Quantity of items ordered
    Pot* pot;///< Optional pot decoration (nullptr if no pot)

public:
    std::string name;///< Public item name for easy access
    
    /**
     * @brief Default constructor
     * 
     * Creates an OrderItem with default values:
     * - name: "Plant Item"
     * - unitPrice: R150.0
     * - qty: 1
     * - pot: nullptr (no pot)
     */
    OrderItem();

    /**
     * @brief Parameterized constructor
     * @param name Item name
     * @param price Unit price per item
     * @param qty Quantity ordered
     * 
     * Creates an OrderItem with specified values.
     * Initializes pot to nullptr (no pot by default).
     */
    OrderItem(std::string name, double price, int qty);

    /**
     * @brief Destructor
     * 
     * Cleans up dynamically allocated pot if one exists.
     * Checks if pot is not nullptr before deletion to prevent
     * errors with items that don't have pots.
     */
    ~OrderItem();
    
    /**
     * @brief Calculates the subtotal for this item
     * @return Total cost including quantity and pot price
     * 
     * Calculates: (unitPrice × quantity) + pot price (if pot exists)
     * 
     * If item has a pot, the pot's price is added to the subtotal.
     * If no pot exists, only returns unitPrice × quantity.
     */
    double subtotal();

    /**
     * @brief Gets formatted information about the item
     * @return Multi-line string with complete item details
     * 
     * Creates a formatted string containing:
     * - Item name
     * - Quantity
     * - Unit price (with R prefix)
     * - Pot information (if pot exists): color and price
     * - Calculated subtotal (including pot if present)
     * 
     * Example output:
     * @code
     * Name: Rose Plant
     * Quantity: 2
     * Unit Price: R50
     * Pot: Blue pot (R30)
     * Subtotal: R130
     * @endcode
     */
    std::string getInfo();
    
    /**
     * @brief Adds a random pot decoration to the item
     * 
     * Deletes any existing pot and creates a new one with random
     * selection from 5 available pot types:
     * - Red pot: R25.00
     * - Blue pot: R30.00
     * - Green pot: R35.00
     * - Terracotta pot: R20.00
     * - White pot: R28.00
     * 
     * Uses rand() % 5 for random selection.
     * 
     * @note Automatically cleans up existing pot before adding new one
     * @note Pot price is included in subtotal() calculation
     * @note This demonstrates the Decorator pattern concept
     */
    void addPot();

    /**
     * @brief Checks if item has a pot
     * @return true if pot is not nullptr, false otherwise
     * 
     * Inline implementation for quick pot existence check.
     * Used to conditionally display pot information.
     */
    bool hasPot() const { return pot != nullptr; }

    /**
     * @brief Gets the pot associated with this item
     * @return Pointer to Pot object, or nullptr if no pot
     * 
     * Inline implementation provides read-only access to pot.
     * Returns nullptr if item doesn't have a pot.
     * 
     * @note Caller should check hasPot() before using returned pointer
     */
    Pot* getPot() const { return pot; }
};

#endif