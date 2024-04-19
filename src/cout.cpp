#include <iostream>
#include <string>
#include <exception>
//#include "drink.h"
//#include "noalc.h"
//#include "withalc.h" 
//#include "cart.h"
//#include "account.h"
#include "cout.h"

using namespace std;

float Cout::priceCalculation(const float oldPrice, const float sale) {
    return (oldPrice * sale) / 100;
}



void Cout::orderAndExit() {
    short int input;
    cout <<endl << "Would you like to order your cart?" << endl;
    cout << "Press 1 to confirm!" << endl;
    cout << "Press 0 to exit! :(" << endl;
    while (true) {

        cin >> input;
        try {

            if (input == 1) {
                Cout::coutFinishedOrder();
                break;
            }
            else if (input == 0) {
                Cout::coutAbortedOrder();
                break;
            }
            else {
                throw std::invalid_argument("Your choice is invalid. Please try again!");
            }
        }

        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
        }
    }
}




void Cout::menuText() {
    cout << "Choose the index of a product each time your want to add it to your cart! :D"<<endl;
    cout << "If you want to delete a product from your cart, press '20'." << endl;
    cout << "When you are done making your cart, just press 0! :)" << endl << endl;
}



int Cout::textToFinish() {
    cout << endl << "Are you sure you don't want to edit your cart?" << endl;
    cout << "Press 1 to go introduce your delivery information!" << endl;
    cout << "Press 2 to go back to editing your cart!" << endl;
    cout << "Press 0 to exit :(" << endl;
    return 0;
}



void Cout::coutFinishedOrder() {
    cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
}



void Cout::coutAbortedOrder() {
    cout << "We are sorry that you are leaving! See you next time!";
}



void Cout::todaysSales() {
    cout << "Here is today's deal!" << endl;
    underLine();
    cout << "25% off for orders over $30" << endl;
    upperLine();
}



void Cout::underLine() {
    for (int i = 0; i < 30; i ++) {
        cout << "_";
    }
    cout << endl;
}



void Cout::upperLine() {
    for (int i = 0; i < 30; i ++) {
        cout << "‾";
    }
    cout<<endl;
}



void Cout::exitText() {
    cout << "Are you sure you want to exit the app?" << endl;
    cout << "Press 1 to go back to order" << endl;
    cout << "Press 0 to exit" << endl;
}
