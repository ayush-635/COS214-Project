/**
 * @file ExpressDelivery.h
 * @brief Express delivery strategy implementation
 * @author Zaynab Samir
 * 
 * This file implements the express delivery method with 1-2 business day
 * delivery time and R150.00 delivery cost. Includes priority features
 * like same-day dispatch and real-time tracking.
 */

#ifndef EXPRESSDELIVERY_H
#define EXPRESSDELIVERY_H
#include "../DeliveryStrategy/DeliveryStrategy.h"

/**
 * @class ExpressDelivery
 * @brief Concrete strategy for express delivery service
 * 
 * Implements the premium express shipping option with:
 * - Delivery time: 1-2 business days
 * - Cost: R150.00
 * - Priority package with expedited processing
 * - Same-day dispatch if ordered before 2 PM
 * - Real-time tracking capability
 * - Premium packaging included
 * 
 * Features fancy formatted output with box-drawing characters and emojis
 * (⚡🚀🌱🚚💰📋⭐📦📱🎁) to create a premium delivery receipt display.
 * 
 * @note Part of the Strategy design pattern
 */
class ExpressDelivery : public DeliveryStrategy {
public:
    /**
     * @brief Delivers an order using express shipping
     * @param order Constant reference to the order to be delivered
     * 
     * Displays beautifully formatted express delivery information including:
     * - Delivery method header with lightning bolt emojis ⚡
     * - Estimated delivery time (1-2 business days)
     * - Order subtotal
     * - Express delivery fee (R150.00)
     * - Total amount (order + delivery)
     * - Number of items in order
     * - Priority processing notification
     * - Same-day dispatch eligibility (before 2 PM)
     * - Real-time tracking availability
     * - Premium packaging notice
     * 
     * Uses emojis for visual appeal and to emphasize premium service.
     */
    void deliver(const Order& order) override;
    
    /**
     * @brief Gets the express delivery cost
     * @return 150.0 (R150.00 express delivery fee)
     * 
     * Inline implementation returns the fixed premium cost for express delivery.
     * This is 3x the cost of standard delivery due to expedited processing.
     */
    double getDeliveryCost() const override { return 150.0; }
    
    /**
     * @brief Gets the delivery type name
     * @return "Express Delivery"
     * 
     * Inline implementation returns the display name for this premium delivery method.
     */
    std::string getDeliveryType() const override { return "Express Delivery"; }
};

#endif
