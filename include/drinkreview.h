#ifndef DRINKREVIEW_H
#define DRINKREVIEW_H


#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <cctype>
#include <algorithm>
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
            cout << bauturica1 << " " << bauturica2;
            cout << endl;

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


    void makeReviewProduct(ReviewProduct *review, const string &nume, short int input0, vector<Drink *> menu) {
        string drink;
        short int input2;

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
        float n1, n2, n3;
        cout << "Well, let's grade your choice, which is: " << drink << endl;

        cout << "First of all, please grade the taste of the product: " << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        categories["Taste"] = opinie;

//        if constexpr (std::is_arithmetic<T>::value) {
//            if (opinie < 0 || opinie > 5) {
//                review->checkGrade(opinie);
//            }
//            categories["Taste"] = opinie;
////            n1 = float(opinie);
//        }

        cout << "Now let us know how you found our packaging. Is it eco-friendly enough and easy to use?" << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        categories["Packaging"] = opinie;

//        if constexpr (std::is_arithmetic<T>::value) {
//            if (opinie < 0 || opinie > 5) {
//                review->checkGrade(opinie);
//            }
//            categories["Taste"] = opinie;
////            n2 = float(opinie);
//        }

        cout << "Last but not least, would you say that the product was worth the money?" << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        categories["Price-Quality Ratio"] = opinie;

//        if constexpr (std::is_arithmetic<T>::value) {
//            if (opinie < 0 || opinie > 5) {
//                review->checkGrade(opinie);
//            }
//            categories["Taste"] = opinie;
////            n3 = float(opinie);
////            (*review)[nume] = float(n1 + n2 + n3);
//        }

        cout << "Thank you for your time! Have a nice day!" << endl;
    };
};

#endif // DRINKREVIEW_H

//        cout <<
//        cin >> review[nume];

//        if (input0 == 1) {
//            float nota;
//
//
//
//        }

//        if (stoi(review[nume]) || (checkWords(review[nume]) == true)) {
//            if (checkWords(review[nume]) == true) {
//                checkGrade(review[nume]);
//            }
//            else {
//                checkGrade(review[nume]);
//            }
//            cout << "Thank you! WOuld you like to go ahead and answer to a few more questions?" << endl;
//            cout << "Press 1 for yes" << endl;
//            cout << "Press 0 for no" << endl;
//            cin >> input2;
//
//            if (input2 == 0) {
//                cout << "Thank you for your time! Hope to see you soon!" << endl;
//            }
//            else {
//                float grade;
//                cout << "Thank you! This won't take too long, we promise" << endl;
//                if (stoi(review[nume]) == true) {
//                    cout << "Please give a grade to the interface of the app: ";
//                    cin >> grade;
//                    ReviewProduct::checkGrade(grade);
//                    review["Interface"] = grade;
//
//                    cout << "Now give a grade to the functionality of our appllication: ";
//                    cin >> grade;
//                    ReviewProduct::checkGrade(grade);
//                    review["Functionality"] = grade;
//
//                    cout << "Last but not least, please rate how you found the payment process through our app: ";
//                    cin >> grade;
//                    ReviewProduct::checkGrade(grade);
//                    review["Payment"] = grade;
//
//                    cout << "You are done! Thank you so much for your help!" << endl;
//                }
//            }
//        }
//        else if (checkWords(review[nume]) == false) {
//            cout << "We are sorry, but your review violates our policies." << endl;
//        }
//    }
//
//
//
//}; 
