#include <iostream>
#include <string>
#include <fstream>
#include <exception>
//#include "drink.h"
//#include "noalc.h"
//#include "withalc.h"
//#include "cart.h"
#include "account.h"
//#include "cout.h"

using namespace std;

Account::Account(const std::string &nume, std::string parola): userName(nume), password(std::move(parola)) {}


Account::Account(const Account& cont): userName(cont.userName), password(cont.password) {}


string Account::getName() const {
    return userName;
}


int Account::exc() {
    short int input;
    while (true) {
        cin >> input;
        try {
            if (input == 1) {
                cout << "Secret code: ";
                return 1;
                //break;
            }
            else if (input == 2) {
                cout << "Password: ";
                return 2;
                //break;
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



void Account::userRead() {
    short int input;
    cout << "Username: ";
    cin >> userName;
    cout << "If you do not remember your password and want to enter your secret code, press 1; for password, press 2"
         << endl;
    if (exc() == 1) {
        while (true) {
            try {
                short int q = 0;
                cin >> password;
                for (short int i = 0; i < int(size(password)); i++) {
                    if (!isdigit(password[i])) {
                        q = -1;
                        throw std::invalid_argument("Your choice is invalid. Please try again!");
                    }
                }
                if (q == 0) {
                    break;
                }
            }
            catch (const std::exception &e) {
                std::cerr << "Error: " << e.what() << std::endl;
                cin.clear();
            }

        }
    }
    else {
        cin >> password;
    }

    Account cont(userName, password);
    save();
    cout << endl << "You are currently using the free version of the app. Would you like to update to one of our exclusive versions?" << endl;
    cout << "Press 1 to see our options" << endl;
    cout << "Press 0 to go ahead with this version" << endl;

    while (true) {
        cin >> input;
        try {
            if (input == 0) {
                cout << "Are you sure?" << endl;
                cout << "Press 1 to change" << endl;
                cout << "Press 0 to confirm" << endl;
                cin >> input;
                if (input == 0) {
                    cout << "Ok, thank you for your time! Hope you will enjoy our services!";
                    break;
                }
                else if (input == 1){
                    Account::premiumText();
                    Account::upgrade();
                    break;
                }
                else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }
            }
            else if (input == 1){
                Account::premiumText();
                Account::upgrade();
                break;
            }
            else {
                throw std::invalid_argument("Your choice is invalid. Please try again!");
            }
        }
        catch (const std::exception& e) {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
        }
    }
}



void Account::premiumText() {

    cout << "Discover the advantages of premium! With our premium accounts, you can have advatages for yourself or for your team as well!" << endl;
    cout << "Premium advatages:" << endl;
    cout << "Collect stars for discounts (you can either keep them for yourself or give them to a friend, who must have a premium/premium plus/business casual account as well)" << endl;
    cout << "Exclusive discounts at our products" << endl;
    cout << "Priority at delivery" << endl << endl;

    cout << "Premium Plus advatages: " << endl;
    cout << "Exclusive access to unreleased coffee products" << endl;
    cout << "at every 5 orders, the 6th one has 90% off" << endl;
    cout << "Collect stars for discounts (you can either keep them for yourself or give them to a friend, who must have a premium/premium plus/business casual account as well)" << endl;
    cout << "Exclusive discounts at our products" << endl;
    cout << "Priority at delivery" << endl << endl;

}


void Account::inputData() {
    string data;
    cout << endl << endl << "Step 2: introduce your credit card information: " << endl;
    cout << "Card number: ";
    cin >> data;
    cout << "Card holder: ";
    cin >> data;
    cout << "CVV/CVC (if the card does not have this, write -1): ";
    cin >> data;
}

string Account::inputVisual(short int input) {
    string data;
    //cin >> input;
    switch(input) {
        case 1:
            data = "Premium plus";
            break;
        case 2:
            data = "Premium";
            break;
        case 3:
            data = "Business casual";
            break;
        case 0:
            data = "abort mission";
            break;
    }
    return data;
}

void Account::upgrade() {
    short int input;
    string tip;
    cout << "Premium - 3.99/month : press 1" << endl;
    cout << "Premium plus - 5.49/month : press 2" << endl;
    cout << "Press 0 to cancel" << endl;


    while (true) {
        cin >> input;
        try {
            if (input == 1 || input == 2) {
                tip = inputVisual(input);
                //cout << tip;
                if (tip == "abort mission") {
                    cout << "Are you sure?" << endl;
                    cout << "Press 1 to change" << endl;
                    cout << "Press 0 to exit" << endl;
                    cin >> input;
                    if (inputVisual(input) != "abort mission") {
                        inputData();
                        cout << endl << "Are you sure you want to confirm your subscription?" << endl;
                        cout << "Press 1 to confirm" << endl;
                        cout << "Press 0 to exit" << endl;
                        cin >> input;
                        if (input == 1) {
                            cout << "We are proceeding your payment..." << endl;
                            cout << "Payment done successfully" << endl;
                            cout << "Thank you for your loyalty!" << endl;
                            break;
                        }
                        else if (input == 0) {
                            cout << "We are sorry to see your leave! Whenever you change your mind, you can come back!"<< endl;
                            break;
                        }
                        else {
                            throw std::invalid_argument("Your choice is invalid. Please try again!");
                        }
                    }
                }
                else {
                    inputData();
                    cout << endl << "Are you sure you want to confirm your subscription?" << endl;
                    cout << "Press 1 to confirm" << endl;
                    cout << "Press 0 to decline" << endl;
                    cin >> input;
                    if (input == 1) {
                        cout << "We are proceeding your payment..." << endl;
                        cout << "Payment done successfully" << endl;
                        cout << "Thank you for your loyalty!" << endl;
                        break;
                    }
                    else {
                        cout << "We are sorry to see your leave! Whenever you change your mind, you can come back!"<< endl;
                        break;
                    }
                }
            }
            else if (input == 0) {
                cout << "Thank you for your time. You can always change your option" << endl;
                break;
            }
            else {
                throw std::invalid_argument("Your choice is invalid. Please try again!");
            }
        }
        catch (const std::exception &e) {
            cerr << "Error: " << e.what() << endl;
            cin.clear();
        }
    }
}



void Account::save() {
    try {
        ofstream f("date.txt");
        if (!f.is_open()) {
            throw std::runtime_error("Problem!");
        }
        else {
            f << userName << endl << password;
            f.close();
        }
    }
    catch (const std::exception &e) {
        std::cerr << "The process could not be executed " << e.what() << endl;
        cin.clear();
    }
}




Account& Account::operator=(const Account &acesta) {
    if (this != &acesta) {
        userName = acesta.userName;
        password = acesta.password;
    }
    return *this;
}


std::ostream& Account::operator<<(std::ostream& coutt) const {
    coutt << "Username: " << userName << endl;
    cout << "Password: " << password << endl;
    return coutt;
}

std::istream& Account::operator>>(std::istream& cinn) {
    cinn >> userName >> password;
    return cinn;
}

Account::~Account() {};
