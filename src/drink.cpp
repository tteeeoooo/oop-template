#include <iostream>
#include <string>
#include <vector>
#include "drink.h"
#include "noalc.h"
#include "withalc.h"
#include "cart.h"
#include "account.h"
#include "cout.h"

using namespace std;


Drink::Drink(const std::string &drinkName, const double &priceTag): drinkChoice(drinkName), price(priceTag) {}

Drink& Drink::operator=(const Drink &bauturica) {
    if (this != &bauturica) {
        this -> drinkChoice = bauturica.drinkChoice;
        this -> price = bauturica.price;
    }
    return *this;
}


void Drink::description() const {};


double Drink::priceModifier() const {
    return price;
}


std::ostream& Drink::operator<<(std::ostream& coutt) {return coutt;}


string Drink::getDrinkName() {
    return drinkChoice;
}

double Drink::getDrinkPrice() const{
    return price;
}


void Drink::menuOptions(vector<Drink*> coffeeMenu) {
    cout << endl << "Here are your options:" << endl;
    for (int x = 0; x < int(coffeeMenu.size()); x++) {
        cout << "Product " << x + 1 << ": " << coffeeMenu[x]->getDrinkName() << " - price with 19% TVA: " << coffeeMenu[x] -> priceModifier() << " " << endl;
    }
}

Drink::~Drink(){};

double operator -(const Drink &bauturica, double procent) {
    double reducere = (bauturica.getDrinkPrice() * procent) / 100;
    return bauturica.getDrinkPrice() + reducere;
}
