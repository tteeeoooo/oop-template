#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <unordered_set>
#include "reviewDrink.h"
#include "templateBase.h"
#include "account.h"
#include "reviewapp.h"
using namespace std;

//template<typename T>
//class Review;

template <typename T>
void ReviewApp<T>::makeReviewApp(ReviewApp review, const Account& user) {
    string name = user.getName();
    short int input2;

    cout << "Here are other users' reviews" << endl;

    ReviewApp::printReviews();

    cout << "Thank you for taking your time to help us improve our app, " << name
         << "! You can either rate us using grades or your own words!" << endl;
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
                ReviewApp::checkGrade(grade);
                review["Interface"] = grade;

                cout << "Now give a grade to the functionality of our appllication: ";
                cin >> grade;
                ReviewApp::checkGrade(grade);
                review["Functionality"] = grade;

                cout << "Last but not least, please rate how you found the payment process through our app: ";
                cin >> grade;
                ReviewApp::checkGrade(grade);
                review["Payment"] = grade;

                cout << "You are done! Thank you so much for your help!" << endl;
            }
        }
    }
    else if (checkWords(review[name]) == false) {
        cout << "We are sorry, but your review violates our policies." << endl;
    }
}
