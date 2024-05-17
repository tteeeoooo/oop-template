#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <unordered_set>
#include "reviewDrink.h"
#include "templateBase.h"
#include "account.h"
#include "reviewapp.h"
#include "cart.h"
#include "drink.h"
using namespace std;

class Account;

class Drink;

template<typename T>
class Review;


template<typename T>
bool checkDrinkList(Cart cart, const string& drinkName) {
    for (int x = 0; x < int(size(cart.getDrinks(cart))); x++) {
        string bauturica1 = cart.getDrinks(cart)[x]->getDrinkName(), bauturica2 = drinkName;
        std::transform(bauturica1.begin(), bauturica1.end(), bauturica1.begin(), [](unsigned char c) { return std::tolower(c); });
        std::transform(bauturica2.begin(), bauturica2.end(), bauturica2.begin(), [](unsigned char c) { return std::tolower(c); });

        if (bauturica1 == bauturica2) {
            return true;
        }
    }
    return false;
}

template<typename T>
void ReviewProduct<T>::makeReviewProduct(ReviewProduct review, const Account& user, Cart cart) {
    string name = user.getName();
    string drink;
    short int input2;

    cout << "Here are other users' reviews" << endl;

    ReviewProduct::printReviews();

    cout << "Thank you for taking your time to help us improve our app, " << name
         << "! You can either rate us using grades or your own words!" << endl;
    cout << "But first of all, please tell us the exact name of the product you would like to rate" << endl;

    while (true) {
        try{
            cin >> drink;
            if (checkDrinkListt<T>(cart, drink) == true) {
                break;
            }

            else {
                throw std::invalid_argument("Your choice is not on our menu. Please try again, you might have wrote something wrong");
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
        }
    }

    cin >> review[name];
    if (stoi(review[name]) || (checkWords(review[name]) == true)) { //stoi e ca sa verifice daca e tot sirul unul de numere sau nu
        if (checkWords(review[name]) == true) {
            checkGrade(review[name]);
        }
        else {
            checkGrade(review[name]);
        }
        cout << "Thank you! WOuld you like to go ahead and answer to a few more questions?" << endl;
        cout << "Press 1 for yes" << endl;
        cout << "Press 0 for no" << endl;
        cin >> input2;

        if (input2 == 0) {
            cout << "Thank you for your time! Hope to see you soon!" << endl;
        }
        else {
            float grade;
            cout << "Thank you! This won't take too long, we promise" << endl;
            if (stoi(review[name]) == true) {
                cout << "Please give a grade to the interface of the app: ";
                cin >> grade;
                ReviewProduct::checkGrade(grade);
                review["Interface"] = grade;

                cout << "Now give a grade to the functionality of our appllication: ";
                cin >> grade;
                ReviewProduct::checkGrade(grade);
                review["Functionality"] = grade;

                cout << "Last but not least, please rate how you found the payment process through our app: ";
                cin >> grade;
                ReviewProduct::checkGrade(grade);
                review["Payment"] = grade;

                cout << "You are done! Thank you so much for your help!" << endl;
            }
        }
    }
    else if (checkWords(review[name]) == false) {
        cout << "We are sorry, but your review violates our policies." << endl;
    }
}
