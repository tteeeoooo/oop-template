#include <iostream>
#include <string>
#include "drink.h"
#include "noalc.h"
//#include "withalc.h"
//#include "cart.h"
//#include "account.h"
//#include "cout.h"

using namespace std;

NoAlc::NoAlc(const string &nume, const double &pret, const int &calorii): Drink(nume, pret), calories(calorii) {};

NoAlc::NoAlc(const NoAlc &bauturaSafe){
    this -> drinkChoice = bauturaSafe.drinkChoice;
    this -> price = bauturaSafe.price;
    this -> calories = bauturaSafe.calories;
}

void NoAlc::description() const {
    cout << "This drink contains " << NoAlc::getCalories() << " calories!" << endl;
}


int NoAlc::getCalories() const {
    return calories;
}

double NoAlc::priceModifier() const {
    return price + (price * 19) / 100;
}



std::ostream& NoAlc::operator<<(std::ostream& coutt) {
    coutt << drinkChoice << " " << price << " " << calories;
    return coutt;
}

std::istream& NoAlc::operator>>(std::istream& cinn) {
    cinn >> drinkChoice >> price;
    return cinn;
}


//std::istream& NoAlc::operator>>(std::istream& cinn) {
//    cinn >> drinkChoice >> price >> calories;
//    return cinn;
//}


//    calorieCalc(const vector <NoAlc>& drinkities)


NoAlc& NoAlc::operator=(const NoAlc& hydrating) {
    if (this != &hydrating) {
        drinkChoice = hydrating.drinkChoice;
        price = hydrating.price;
        calories = hydrating.calories;
    }
    return *this;
}


NoAlc::~NoAlc(){};
