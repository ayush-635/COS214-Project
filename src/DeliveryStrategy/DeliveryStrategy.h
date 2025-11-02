/**
 * @file DeliveryStrategy.h
 * @brief Abstract base class for delivery strategy pattern
 * @author Zaynab Samir
 * 
 * This file defines the DeliveryStrategy interface which allows different
 * delivery methods to be used interchangeably. This is part of the Strategy
 * design pattern implementation for order delivery.
 */
#ifndef DELIVERYSTRATEGY_H
#define DELIVERYSTRATEGY_H

#include <iostream>
#include <string>

class Order;

/**
 * @class DeliveryStrategy
 * @brief Abstract base class for delivery strategies
 * 
 * This class defines the interface for all concrete delivery strategy implementations.
 * Each concrete strategy (StandardDelivery, ExpressDelivery, PickupDelivery) implements
 * the deliver() method differently to provide various delivery options with different
 * costs and delivery types.
 * 
 * @note This is part of the Strategy design pattern
 */
class DeliveryStrategy {
public:
    /**
     * @brief Delivers an order using the specific delivery strategy
     * @param order Constant reference to the order to be delivered
     * 
     * Pure virtual function to be implemented by concrete strategies.
     * Each implementation will provide different delivery methods and costs.
     * Uses const reference to avoid unnecessary copying of Order objects.
     */
    virtual void deliver(const Order& order) = 0;

    /**
     * @brief Gets the delivery cost for this strategy
     * @return The cost of delivery in Rands (R)
     * 
     * Pure virtual function that returns the specific delivery cost
     * for each strategy (e.g., R50 for standard, R150 for express, R0 for pickup).
     */
    virtual double getDeliveryCost() const = 0;

    /**
     * @brief Gets the delivery type name for this strategy
     * @return String describing the delivery type (e.g., "Standard", "Express", "Pickup")
     * 
     * Pure virtual function that returns a human-readable name for the
     * delivery method used by this strategy.
     */
    virtual std::string getDeliveryType() const = 0;

    /**
     * @brief Virtual destructor for proper cleanup of derived classes
     */
    virtual ~DeliveryStrategy() {}
    
    /**
     * @brief Default constructor
     */
    DeliveryStrategy();
};

#endif