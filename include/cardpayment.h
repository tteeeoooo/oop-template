#include "payment.h"

class CreditCardPayment : public Payment {
public:
    void pay(const Cart& cart) override;
};

#ifndef OOP_CARDPAYMENT_H
#define OOP_CARDPAYMENT_H

#endif //OOP_CARDPAYMENT_H
