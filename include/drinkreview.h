#ifndef DRINKREVIEW_H
#define DRINKREVIEW_H


#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <cctype>
#include <algorithm>
#include <limits>
#include "drink.h"

using namespace std;

class Account;

class Drink;


template<typename T>
class Review;

template <typename T>
class ReviewProduct: public Review<T> {
private:
    std::map<std::string, T> categories;

public:
    explicit ReviewProduct(std::map<std::string, T> *firstReview) : Review<T>(firstReview) {
        this->categories["Taste"] = T{};
        this->categories["Packaging"] = T{};
        this->categories["Price-Quality Ratio"] = T{};
    }

    explicit ReviewProduct(const Review<T> &rev) : Review<T>(rev.getReview()) {
        this->categories["Taste"] = T{};
        this->categories["Packaging"] = T{};
        this->categories["Price-Quality Ratio"] = T{};
    }

    ReviewProduct(const T &productId, const std::string &description) : Review<T>(productId, description) {};


    bool checkDrinkList(vector<Drink *> menu, const string &drinkName) {
        string bauturica2 = drinkName;
        std::transform(bauturica2.begin(), bauturica2.end(), bauturica2.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        string bauturica1;
        for (int x = 0; x < int(size(menu)); x++) {
            bauturica1 = menu[x]->getDrinkName();
            std::transform(bauturica1.begin(), bauturica1.end(), bauturica1.begin(),
                           [](unsigned char c) { return std::tolower(c); });

            if (bauturica1 == bauturica2) {
                auto asd = [menu]() {
                    for (auto &a: menu) {
                        delete a;
                    }
                };
                asd();
                return true;
            }
        }
        auto asd = [menu]() {
            for (auto &a: menu) {
                delete a;
            }
        };
        asd();
        return false;
    }


    void makeReviewProduct(const vector<Drink *>& menu) {
        string drink;

        cout << "Thank you for taking your time to help us improve our app!" << endl
             << "! You can either rate us using grades or your own words!" << endl;
        cout << "But first of all, please tell us the exact name of the product you would like to rate" << endl;

        while (true) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, drink);

            bool verificare = checkDrinkList(menu, drink);

            if (verificare == true) {
                break;
            }
        }
        T opinie;
        cout << "Well, let's grade your choice, which is: " << drink << endl;

        cout << "First of all, please grade the taste of the product: " << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        categories["Taste"] = opinie;



        cout << "Now let us know how you found our packaging. Is it eco-friendly enough and easy to use?" << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        categories["Packaging"] = opinie;



        cout << "Last but not least, would you say that the product was worth the money?" << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        categories["Price-Quality Ratio"] = opinie;



        cout << "Thank you for your time! Have a nice day!" << endl;
    };
};

#endif // DRINKREVIEW_H


