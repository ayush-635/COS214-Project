/**
 * @file OrderItem.cpp
 * @brief Implementation of OrderItem class
 * @author Zaynab Samir
 */

#include "OrderItem.h"
#include <iostream>
#include <cstdlib>

/**
 * @brief Default constructor implementation
 * 
 * Initializes with default plant item values and no pot.
 */
OrderItem::OrderItem() {
    name = "Plant Item";
    unitPrice = 150.0;
    qty = 1;
    pot = nullptr;
}

/**
 * @brief Parameterized constructor implementation
 * 
 * Initializes with user-specified values and sets pot to nullptr.
 * 
 * @param name Item name
 * @param price Unit price
 * @param qty Quantity
 */
OrderItem::OrderItem(std::string name, double price, int qty) {
    this->name = name;
    unitPrice = price;
    this->qty = qty;
    pot = nullptr;
}

/**
 * @brief Destructor implementation
 * 
 * Safely deletes the pot if one exists.
 * Checks for nullptr before deletion to avoid errors.
 */
OrderItem::~OrderItem() {
    if (pot) {
        delete pot;
    }
}

/**
 * @brief Calculates item subtotal with pot price
 * 
 * Computes base cost (unitPrice × qty) and adds pot price if present.
 * 
 * @return Total cost including pot decoration if applicable
 */
double OrderItem::subtotal() {
    double total = qty * unitPrice;
    if (pot) {
        total += pot->getPrice();
    }
    return total;
}

/**
 * @brief Generates formatted item information string
 * 
 * Uses stringstream for efficient string building.
 * Conditionally includes pot information if pot exists.
 * 
 * Format includes:
 * - Name: [item name]
 * - Quantity: [qty]
 * - Unit Price: R[price]
 * - Pot: [color] pot (R[pot price]) [if pot exists]
 * - Subtotal: R[total including pot]
 * 
 * @return Formatted multi-line string with all item details
 */
std::string OrderItem::getInfo() {
    std::stringstream oss;
    oss << "Name: " << name << "\n";
    oss << "Quantity: " << qty << "\n";
    oss << "Unit Price: R" << unitPrice << "\n";
    if (pot) {
        oss << "Pot: " << pot->getColour() << " pot (R" << pot->getPrice() << ")\n";
    }
    oss << "Subtotal: R" << subtotal() << "\n";
    return oss.str();
}

/**
 * @brief Adds a randomly selected pot decoration
 * 
 * Implementation details:
 * 1. Cleans up existing pot if present (prevents memory leak)
 * 2. Defines 5 pot types with colors and prices in local struct array
 * 3. Randomly selects one using rand() % 5
 * 4. Creates new Pot with selected type's properties
 * 
 * Available pot types:
 * - Red: R25.00 (index 0)
 * - Blue: R30.00 (index 1)
 * - Green: R35.00 (index 2)
 * - Terracotta: R20.00 (index 3)
 * - White: R28.00 (index 4)
 * 
 * @note Uses rand() for random selection - seed with srand() if needed
 * @note Pot price range: R20-R35
 * @note Always safe to call - cleans up existing pot automatically
 */
void OrderItem::addPot() {
    // Clean up existing pot if any
    if (pot) {
        delete pot;
        pot = nullptr;
    }
    
    struct PotType {
        std::string color;
        double price;
    };
    
    PotType potTypes[] = {
        {"Red", 25.0},
        {"Blue", 30.0},
        {"Green", 35.0},
        {"Terracotta", 20.0},
        {"White", 28.0}
    };
    
    int randomIndex = rand() % 5;
    pot = new Pot(potTypes[randomIndex].color, 1, potTypes[randomIndex].price);
}
