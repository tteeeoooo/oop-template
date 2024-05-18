#include "cashpayment.h"
#include "cout.h"
#include "cardpayment.h"
#include "cart.h"
#include <iostream>
#include <stdexcept>
#include "payment.h"


using namespace std;

void CreditCardPayment::pay(const Cart& cart) {
    long int creditCard;
    short int input;
    cout << "Introduce your credit card information" << endl;
    cout << "Card number: ";
    cin >> creditCard;
    cout << "CVV/CVC/CVC2: ";
    cin >> input;
    cout << endl << "Would you like to give a tip to the delivery person?" << endl;
    cout << "Press 1 for yes! :)" << endl;
    cout << "Press 0 for no!" << endl;
    cin >> input;
    try {
        if (input == 1) {
            cart.giveATip(cart);
        }
        else if (input == 0){
            Cout::orderAndExit();
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
