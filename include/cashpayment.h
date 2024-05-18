#ifndef OOP_PAYMENT_H
#define OOP_PAYMENT_H

#include "payment.h"

class AtAddressPayment : public Payment {
public:
    void pay(const Cart& cart) override;
};


#endif //OOP_PAYMENT_H
