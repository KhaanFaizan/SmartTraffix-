#include "StripePayment.h"

StripePayment::StripePayment() {}

bool StripePayment::processPayment(int challanId, int amount) {
    // Simulate payment processing (e.g., via Stripe API)
    std::cout << "Processing payment for Challan ID " << challanId << " Amount: " << amount << " PKR\n";

    // Simulate successful payment
    std::cout << "Payment successful!\n";
    return true;
}
