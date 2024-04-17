#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;


class Cart {
private:
    vector<Drink*> myDrinks;            //vector de bauturi din cos => neaparat sa invat cum functioneaza vectorii in C++!!!!
    float price;                        //suma care urmeaza sa fie platita
    vector<float> priceList;            //lista prteurilor

public:
    explicit Cart(const vector<Drink *> &bauturi = {}, float pret = 0, const vector<float> &preturi = {});
    Cart(const Cart &cos);
    void productDelete(int index);
    float cartPrice() const;
    vector<Drink*> getDrinks(Cart cart);

    Cart& operator=(const Cart& shopping);
    friend std::ostream& operator<<(std::ostream& coutt, const Cart& cart);

    void atAddressPayment(const Cart &cart);
    static void creditCardInfo(const Cart &cart);
    float order(Cart &cart, vector<Drink*> coffeeMenu);
    void readyToOrder(Cart &cart, const vector<Drink*>& coffeeMenu);
    void deliveryAddress(const Cart &cart);
    void giveATip(const Cart &cart) const;
    int everything(Cart cart, const vector<Drink*> &coffeeMenu);

    virtual ~Cart();
};
