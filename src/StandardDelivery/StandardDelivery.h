/**
 * @file StandardDelivery.h
 * @brief Standard delivery strategy implementation
 * @author Zaynab Samir
 * 
 * This file implements the standard delivery method with 3-5 business day
 * delivery time and R50.00 delivery cost.
 */
#ifndef STANDARDDELIVERY_H
#define STANDARDDELIVERY_H

#include "../DeliveryStrategy/DeliveryStrategy.h"

/**
 * @class StandardDelivery
 * @brief Concrete strategy for standard delivery service
 * 
 * Implements the standard shipping option with:
 * - Delivery time: 3-5 business days
 * - Cost: R50.00
 * - Doorstep delivery with careful packaging
 * - Standard courier shipping
 * 
 * Features fancy formatted output with box-drawing characters and emojis
 * to create a professional delivery receipt display.
 * 
 * @note Part of the Strategy design pattern
 */
class StandardDelivery : public DeliveryStrategy {
public:
    /**
     * @brief Delivers an order using standard shipping
     * @param order Constant reference to the order to be delivered
     * 
     * Displays beautifully formatted delivery information including:
     * - Delivery method header with box-drawing characters
     * - Estimated delivery time (3-5 business days)
     * - Order subtotal
     * - Delivery fee (R50.00)
     * - Total amount (order + delivery)
     * - Number of items in order
     * - Packaging and delivery assurances
     */
    void deliver(const Order& order) override;
    /**
     * @brief Gets the standard delivery cost
     * @return 50.0 (R50.00 standard delivery fee)
     * 
     * Inline implementation returns the fixed cost for standard delivery.
     */
    double getDeliveryCost() const override { return 50.0; }

    /**
     * @brief Gets the delivery type name
     * @return "Standard Delivery"
     * 
     * Inline implementation returns the display name for this delivery method.
     */
    std::string getDeliveryType() const override { return "Standard Delivery"; }
};

#endif