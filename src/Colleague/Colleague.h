/**
 * @file Colleague.h
 * @author Ayush Sanjith
 * @brief Header file for the Colleague class
 */

#ifndef COLLEAGUE_H
#define COLLEAGUE_H
#include <string>
#include "../Mediator/Mediator.h"

class Mediator;

/**
 * @class Colleague
 * @brief Base class for objects that communicate through a mediator
 */
class Colleague {

protected:
    Mediator* mediator; /**< Pointer to the mediator for communication */

public:
    /**
     * @brief Default constructor
     */
    Colleague();

    /**
     * @brief Receive advice from mediator
     * @return Advice string
     */
    virtual std::string receiveAdvice();

    /**
     * @brief Set the mediator for this colleague
     * @param m Pointer to the mediator
     */
    void setMediator(Mediator* m);

    /**
     * @brief Virtual destructor
     */
    virtual ~Colleague();

    /**
     * @brief Constructor with mediator
     * @param m Pointer to the mediator
     */
    Colleague(Mediator* m);
    
    /**
     * @brief Get the mediator
     * @return Pointer to the mediator
     */
    Mediator* getMediator() const;
};

#endif
