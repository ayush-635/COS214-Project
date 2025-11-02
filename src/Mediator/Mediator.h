/**
 * @file Mediator.h
 * @author Ayush Sanjith
 * @brief Header file for the Mediator class
 */

#ifndef MEDIATOR_H
#define MEDIATOR_H
#include <string>

class Colleague;

/**
 * @class Mediator
 * @brief Abstract base class for mediator pattern
 */
class Mediator {

public:
    /**
     * @brief Notify a colleague
     * @param colleague Colleague to notify
     * @param msg Message to send
     */
    virtual void notify(Colleague* colleague, std::string msg) = 0;

    /**
     * @brief Default constructor
     */
    Mediator();
    
    /**
     * @brief Virtual destructor
     */
    virtual ~Mediator(){};
};

#endif