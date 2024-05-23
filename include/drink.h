#ifndef DRINK_H
#define DRINK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Drink {
protected:
    string drinkChoice;       //tipul bauturii
    double price;
public:
    explicit Drink(const std::string &drinkName = "", const double &priceTag = 0);
    Drink(const Drink &bauturica) = default;

//    virtual string consume() = 0;



    Drink &operator=(const Drink &bauturica);

    virtual void description() const = 0;
    virtual double priceModifier() const = 0;

//    std::ostream& operator<<(std::ostream& coutt) const;
    virtual std::ostream& operator<<(std::ostream& coutt) = 0;
    std::istream& operator>>(std::istream& cinn);

    string getDrinkName();
    double getDrinkPrice() const;
    static void menuOptions(vector<Drink*> coffeeMenu);
    virtual ~Drink();
};
double operator -(const Drink &bauturica, double procent);



#endif // DRINK_H
