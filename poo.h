#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

#ifndef OOP_POIECT_H
#define OOP_POIECT_H


void menuText();

float priceCalculation(float oldPrice, float sale);

void underLine();

void upperLine();

int textToFinish();

void orderAndExit() ;

void coutFinishedOrder();

void coutAbortedOrder();

void todaysSales();


class Drink {
protected:
    string drinkChoice;       //tipul bauturii
    double price;
public:
    explicit Drink(std::string drinkName = "", const double &priceTag = 0);
    Drink(const Drink &bauturica);

    Drink &operator=(const Drink &bauturica);

    virtual void description() const = 0;
    virtual double priceModifier() const = 0;

    std::ostream& operator<<(std::ostream& coutt) const;
    std::istream& operator>>(std::istream& cinn);

    string getDrinkName();
    double getDrinkPrice() const;
    static void menuOptions(vector<Drink*> coffeeMenu);
    virtual ~Drink();
};
double operator -(const Drink &bauturica, double procent);



class NoAlc: public Drink {
private:
    int calories;
public:
    explicit NoAlc(const string &nume = "", const double &pret = 0, const int &calorii = 0);
    NoAlc(const NoAlc &notGood);
    void description() const override;
    int getCalories() const;
//    virtual void setAlc(int percent) const = 0;
    double priceModifier() const override;

    std::ostream& operator<<(std::ostream& coutt) const;
    std::istream& operator>>(std::istream& cinn);
    NoAlc& operator=(const NoAlc& hydrating);

    virtual ~NoAlc();
};



class WithAlc: public Drink {
private:
    int alcohol;
public:
    explicit WithAlc(const string &nume = "", const double &pret = 0, const int &alc = 0);
    WithAlc(const WithAlc &notGood);
    void setAlc(int percent);

    void description() const override;
    int getAlc() const;
    double priceModifier() const override;
    static bool ageCheck();

    std::ostream& operator<<(std::ostream& coutt) const;
    std::istream& operator>>(std::istream& cinnn);
    WithAlc& operator=(const WithAlc& hydratingg);

    virtual ~WithAlc();
};



class Account {
protected:
    string userName;
    string password;
public:
    explicit Account(const string &nume = "", string parola = "");
    Account(const Account &cont);
    string getName() const;

    void exc();
    void userRead();
    void premiumText();
    void inputData();

    string inputVisual(short int input);
    void upgrade();
    virtual void save();

    Account& operator=(const Account &acesta);
    std::ostream& operator<<(std::ostream& coutt) const;
    std::istream& operator>>(std::istream& cinn);

    virtual ~Account();
};



class Cart {
private:
    vector<Drink *> myDrinks;            //vector de bauturi din cos => neaparat sa invat cum functioneaza vectorii in C++!!!!
    float price;                        //suma care urmeaza sa fie platita
    vector<float> priceList;            //lista prteurilor

public:
    explicit Cart(const vector<Drink *> &bauturi = {}, float pret = 0, const vector<float> &preturi = {});
    Cart(const Cart &cos);
    void productDelete(int index);
    float cartPrice() const;
    vector<Drink*> getDrinks(Cart cart);

    Cart& operator=(const Cart& shopping);
    //std::ostream& operator<<(ostream& coutt);
    friend std::ostream& operator<<(std::ostream& os, const Cart& cart);

    void atAddressPayment(const Cart &cart);
    static void creditCardInfo(const Cart &cart);
    float order(Cart &cart, vector<Drink*> coffeeMenu);
    void readyToOrder(Cart &cart, const vector<Drink*>& coffeeMenu);
    void deliveryAddress(const Cart &cart);
    void giveATip(const Cart &cart) const;
    static int everything(Cart cart, const vector<Drink*> &coffeeMenu);

    virtual ~Cart();
};

#endif //OOP_POIECT_H

#ifndef OOP_POO_H
#define OOP_POO_H

#endif //OOP_POO_H
