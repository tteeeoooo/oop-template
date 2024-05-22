#include "drink.h"
#include "noalc.h"
#include "withalc.h"
#include "cart.h"
#include "account.h"
#include "cout.h"
#include "payment.h"
#include "review.h"
#include "drinkreview.h"
#include "appreview.h"
#include <unordered_map>


//template <typename T>
//class Review;


int main() {
    Cart cart({}, 0, {});
    //Account user("", "", nullptr);
    Account* user = Account::getInstance();

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

    cout << "Chamberlain Coffee - Easy Mobile & Online Ordering & Delivery" << endl;
    Cout::todaysSales();

    cout << "Connect to your account: " << endl;
    user -> userRead();


    cout << "Well hello " << user -> getName() << "! We are glad to have you back! :)" << endl;
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
                } else if (input == 1) {
                    cart.everything(cart, menu);
                    asd();
                    return 0;
                } else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }
            }
            else {
                cart.everything(cart, menu);

                cout << "Would you like to help us with a review?" << endl;
                cout << "Press 1 for yes" << endl;
                cout << "Press 0 for no" << endl;
                cin >> input;

                if (input == 0) {
                    cout << "Thank you for using our app! Have a good day!" << endl;
                    asd();
                    return 0;
                }
                else {
                    cout << "Would you like to use grades or your own words?" << endl;
                    cout << "Press 1 for grades" << endl;
                    cout << "Press 2 for more detailed notes" << endl;
                    cin >> input;

                    string user2 = user -> getName();
                    if (input == 1) {
                        Review<float> review(user2, 0.0);
                        Review<float>::makeReview(review, user2, menu);
                    }
                    else {
                        Review<string> review(user2, "");
                        Review<string>::makeReview(review, user2,  menu);
                    }
                    asd();
                    return 0;
                }

                asd();
                return 0;
            }
        }

        catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
        }
    }
    asd();
    return 0;

}



//cout << "Would you like to give a review to a product or to our application?";
//cout << "Press 1 for app" << endl;
//cout << "Press 2 for application" << endl;
//
//
//Review<string> parere(user.getName(), "");
//Review<T>: makeReview(parere, input);

//else {
//        asd();
//        return 0;
//    }
//
//                else {
//                    cout << "Thank you for your time. Have a good day!" << endl;
//                    asd();
//                    return 0;
//                }
//
//                asd();
//                return 0;
//            }



















//cout << "Would you like to give a review to our products?" << endl;
//cout << "Press 1 for yes" << endl;
//cout << "Press 0 for no" << endl;
//cin >> input;
//if(input == 1) {
//cout << "Would you like to give a review to a product or our app?";
//cout << "Press 1 for non-alcoholic" << endl;
//cout << "Press 2 for alcoholic" << endl;
//
//if(input == 1) {
//Review<string> parere(user.getName(), "");
//cout << parere;
//}


//if (input == 1){
//cart.everything(cart, menu);
//cout << endl << "Would you like to give a review to our little business?" << endl;
//cout << "Press 1 for yes" << endl;
//cout << "Press 0 for no" << endl;
//cin >> input;
//
//if (input == 1) {
//cout << "Would you like to give a review to a product or our app?" << endl;
//cout << "Press 1 for product" << endl;
//cout << "Press 2 for application" << endl;
//
//if (input == 1) {
//cout << "Would you like to use grades or your own words?" << endl;
//cout << "Press 1 for grade" << endl;
//cout << "Press 2 for words" << endl;
//cin >> input;
//
//if (input == 1) {
//float rating = 0;
//Review<float> parere(user.getName(), rating);
//parere.
//makeReview(input);
//}







