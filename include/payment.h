#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Cart;

class Payment {
public:
    virtual void pay(const Cart& cart) = 0;
    virtual ~Payment() = default;
};


#endif //PAYMENT_H
