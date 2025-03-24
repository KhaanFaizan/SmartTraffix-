#ifndef STRIPEPAYMENT_H
#define STRIPEPAYMENT_H

#include <string>
#include <iostream>
#include "ChallanGenerator.h"

class StripePayment {
public:
    StripePayment();
    bool processPayment(int challanId, int amount);
};

#endif

