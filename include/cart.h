#ifndef CART_H
#define CART_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include "drink.h"
#include "payment.h"

using namespace std;


class Cart {
private:
    Payment* paymentStrategy;
    vector<Drink*> myDrinks;
    float price;
    vector<float> priceList;

public:
    explicit Cart(const vector<Drink *> &bauturi = {}, float pret = 0, const vector<float> &preturi = {}): paymentStrategy(nullptr), myDrinks(bauturi), price(pret), priceList(preturi) {};
    Cart(const Cart &cos): paymentStrategy(nullptr), myDrinks(cos.myDrinks), price(cos.price), priceList(cos.priceList) {};
    void productDelete(int index);
    float cartPrice() const;
    vector<Drink*> getDrinks(Cart cart);

    void setPaymentStrategy(Payment* strategy);
    void executePayment();

    Cart& operator=(const Cart& shopping);
    friend std::ostream& operator<<(std::ostream& coutt, const Cart& cart);

    void atAddressPayment(const Cart &cart);
    static void creditCardInfo(const Cart &cart);
    float order(Cart &cart, vector<Drink*> coffeeMenu);
    void readyToOrder(Cart &cart, const vector<Drink*>& coffeeMenu);
    void deliveryAddress(const Cart &cart);
    void giveATip(const Cart &cart) const;
    int everything(Cart cart, const vector<Drink*> &coffeeMenu);

    ~Cart();
};

#endif // CART_H
