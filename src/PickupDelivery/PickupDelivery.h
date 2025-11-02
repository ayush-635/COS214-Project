/**
 * @file PickupDelivery.h
 * @brief Customer pickup delivery strategy implementation
 * @author Zaynab Samir
 * 
 * This file implements the customer pickup method with no delivery cost
 * and 2-4 hour preparation time. Customers collect orders from the
 * Main Nursery location.
 */
#ifndef PICKUPDELIVERY_H
#define PICKUPDELIVERY_H

#include "../DeliveryStrategy/DeliveryStrategy.h"

/**
 * @class PickupDelivery
 * @brief Concrete strategy for customer pickup service
 * 
 * Implements the cost-free customer pickup option with:
 * - Delivery time: 2-4 hours (order preparation)
 * - Cost: R0.00 (FREE - no delivery charge)
 * - Pickup location: Main Nursery - 123 Garden St
 * - Pickup hours: Mon-Sat 8AM-6PM, Sunday 9AM-4PM
 * - Requires ID and order confirmation
 * 
 * Features fancy formatted output with box-drawing characters and emojis
 * to create a customer pickup receipt display.
 * 
 * @note Part of the Strategy design pattern
 * @note This is the most economical option (FREE) but requires customer transportation
 */
class PickupDelivery : public DeliveryStrategy {
public:
    /**
     * @brief Processes an order for customer pickup
     * @param order Constant reference to the order to be picked up
     * 
     * Displays beautifully formatted pickup information including:
     * - Pickup service header with store emoji 🏪
     * - Delivery method (Customer Pickup)
     * - Physical pickup location address
     * - Order subtotal
     * - Delivery fee (R0.00 - FREE)
     * - Total amount (same as subtotal - no additional charges)
     * - Number of items ready for pickup
     * - Order preparation time (2-4 hours)
     * - Required documents (ID and order confirmation)
     * - Detailed pickup hours schedule
     * 
     * Uses emojis for visual appeal and clear information presentation.
     */
    void deliver(const Order& order) override;

    /**
     * @brief Gets the pickup delivery cost
     * @return 0.0 (R0.00 - FREE pickup, no delivery charges)
     * 
     * Inline implementation returns zero as there is no charge for
     * customer pickup. This is the most economical delivery option.
     */
    double getDeliveryCost() const override { return 0.0; }

    /**
     * @brief Gets the delivery type name
     * @return "Customer Pickup"
     * 
     * Inline implementation returns the display name for this free pickup method.
     */
    std::string getDeliveryType() const override { return "Customer Pickup"; }
};

#endif