/**
 * @file Pot.h
 * @author Ayush Sanjith
 * @brief Header file for the Pot class
 */

#ifndef POT_H
#define POT_H

#include <string>

/**
 * @class Pot
 * @brief Represents a plant pot
 */
class Pot {
private:
    std::string colour; /**< Color of the pot */
    int size;          /**< Size of the pot */
    double price;      /**< Price of the pot */

public:
    /**
     * @brief Constructor
     * @param c Color of the pot
     * @param size Size of the pot
     * @param price Price of the pot
     */
    Pot(std::string c, int size, double price);
    
    /**
     * @brief Get pot color
     * @return Color string
     */
    std::string getColour() const { return colour; }
    
    /**
     * @brief Get pot size
     * @return Size value
     */
    int getSize() const { return size; }
    
    /**
     * @brief Get pot price
     * @return Price value
     */
    double getPrice() const { return price; }
};

#endif