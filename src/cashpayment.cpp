#include "cashpayment.h"
#include "cout.h"
#include "cardpayment.h"
#include "cart.h"
#include <iostream>
#include <stdexcept>
#include "payment.h"

using namespace std;

void AtAddressPayment::pay(const Cart& cart) {
    short int input;
    cout << "Are you sure you want to pay at the delivery?" << endl;
    cout << "Press 1 for yes" << endl;
    cout << "Press 0 to switch to credit card payment" << endl;

    while (true) {
        cin >> input;
        try {
            if (input == 1) {
                cout << "You chose at delivery payment." << endl;
            } else {
                cout << "You switched to credit card payment!" << endl;
                CreditCardPayment creditCardPayment;
                creditCardPayment.pay(cart);
                return;
            }
            cout << "Would you like to give a tip to the delivery person?" << endl;
            cout << "Press 1 for yes! :)" << endl;
            cout << "Press 0 for no!" << endl;
            cin >> input;
            if (input == 1) {
                cart.giveATip(cart);
            }
            else if (input == 0) {
                cout << "It's fine!" << endl;
                Cout::orderAndExit();
            }
            else {
                throw std::invalid_argument("Your choice is invalid. Please try again!");
            }
            return; 
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
        }
    }
}
