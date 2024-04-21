#include <iostream>
#include <string>
#include "drink.h"
//#include "noalc.h"
#include "withalc.h"
//#include "cart.h"
//#include "account.h"
//#include "cout.h"

using namespace std;



WithAlc::WithAlc(const string &nume, const double &pret, const int &alc): Drink(nume, pret), alcohol(alc) {};

WithAlc::WithAlc(const WithAlc &bauturaUnsafe){
    this -> drinkChoice = bauturaUnsafe.drinkChoice;
    this -> price = bauturaUnsafe.price;
    this -> alcohol = bauturaUnsafe.alcohol;
}

//WithAlc::WithAlc(const WithAlc& notGood) = default;

//void WithAlc::setAlc(int percent) {
//    alcohol = percent;
//}


void WithAlc::description() const  {
    cout << "This drink contains alcohol in a percentage of " << WithAlc::getAlc() << "%" << endl;
}

int WithAlc::getAlc() const {
    return alcohol;
}


double WithAlc::priceModifier() const {
    double p = price + (price * 19) / 100;
    return p + p / 20;
}   //returneaza pretul cu tva + acciza de 5% pe bauturile alcoolice




bool WithAlc::ageCheck() {
    short int input;
    cout << "Please enter your age: ";
    cin >> input;
    if (input < 21) {
        return false;
    }
    else {
        cout << "You can have access to alcoholic drinks!" << endl;
        cout << "Side note: according to the Romanian regulations regarding selling fo alcoholic drinks, you will be imposed with a 5% excise tax!" << endl;
        return true;
    }
}


std::ostream& WithAlc::operator<<(std::ostream& coutt) {
    coutt << drinkChoice << " " << price << alcohol;
    return coutt;
}


std::istream& WithAlc::operator>>(std::istream& cinnn) {
    cinnn >> drinkChoice >> price >> alcohol;
    return cinnn;
}



WithAlc& WithAlc::operator=(const WithAlc& hydratingg) {
    if (this != &hydratingg) {
        drinkChoice = hydratingg.drinkChoice;
        price = hydratingg.price;
        alcohol = hydratingg.alcohol;
    }
    return *this;
}


WithAlc::~WithAlc() = default;
