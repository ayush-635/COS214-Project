#ifndef POT_H
#define POT_H

#include <string>

class Pot {
private:
    std::string colour;
    int size;
    double price;

public:
    Pot(std::string c, int size, double price);
    
    std::string getColour() const { return colour; }
    int getSize() const { return size; }
    double getPrice() const { return price; }
};

#endif
