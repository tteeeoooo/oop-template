#include "drink.h"
#include "noalc.h"
#include "withalc.h"
#include "cart.h"
#include "account.h"
#include "cout.h"
//#include "drink.cpp"
//#include "cout.cpp"
//#include "noalc.cpp"
//#include "withalc.cpp"
//#include "account.cpp"
#include <functional>


int main() {
    Cart cart({}, 0, {});
    Account user;
    short int input;
    vector<Drink*> menu;


    menu.push_back(new NoAlc("Iced Latte", 5.9, 96));
    menu.push_back(new NoAlc("Cold Brew", 3.9, 23));
    menu.push_back(new NoAlc("Vanilla Bean Crème Frappuccino Blended Crème", 6.8, 407));
    menu.push_back(new NoAlc("Oleato Golden Foam Iced Shaken Espresso With Toffeenut", 7.5, 349));
    menu.push_back(new NoAlc("Vanilla Sweet Cream Cold Brew", 6.5, 90));
    menu.push_back(new NoAlc("Vanilla Cremè", 5.5, 137));
    menu.push_back(new NoAlc("Cinnamon Caramel Cream Cold Brew", 4.0, 203));
    menu.push_back(new NoAlc("Iced Blonde Vanilla Latte", 7.2, 231));
    menu.push_back(new NoAlc("Caramel Ribbon Crunch Frappucino", 6.4, 189));
    menu.push_back(new NoAlc("Iced White Chocolate Mocha", 5.8, 410));
    menu.push_back(new NoAlc("Oleato Golden Foam Iced Shaken Espresso With Toffeenut", 7.5, 349));
    menu.push_back(new NoAlc("Espresso Frappuccino Blended Beverage", 4.8, 278));
    menu.push_back(new NoAlc("Lavender Crème Frappuccino Blended Beverage", 7.5, 428));
    menu.push_back(new NoAlc("Pink Drink Refresher", 4.6, 196));
    menu.push_back(new NoAlc("Matcha Latte", 6.5, 125));
    menu.push_back(new NoAlc("Iced Matcha Tea Latte With Oatmilk", 6.5, 126));
    menu.push_back(new WithAlc("Chateau Lafite Rothschild", 876.0, 15));
    menu.push_back(new WithAlc("Penfolds Grange Hermitage", 763.0, 12));
    menu.push_back(new WithAlc("Chateau d'Yquem", 1973.0, 16));

    auto asd = [menu]() {
        for (auto &a: menu) {
            delete a;
        }
    };




    cout << "Café de Flore - Easy Mobile & Online Ordering & Delivery" << endl;
    Cout::todaysSales();

    cout << "Connect to your account: " << endl;
    user.userRead();

    cout << "Well hello " << user.getName() << "! We are glad to have you back! :)" << endl;
    cout << "What would you like to do today? Choose one of the following options!" << endl;
    cout << "1. Menu" << endl;
    cout << "0. Exit" << endl;



    while(true) {
        try {
            cin >> input;

            if (input == 0) {
                Cout::exitText();
                cin >> input;

                if (input == 0) {
                    cout << "We are sorry to see you leave! We hope you will come back soon!" << endl;
                    asd();
                    return 0;
                }
                else if (input == 1){
                    cart.everything(cart, menu);
                    asd();
                    return 0;
                }
                else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }
            }
            else {
                cart.everything(cart, menu);
                asd();
                return 0;
            }
        }

        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
        }
    }
}







































