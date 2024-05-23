#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include "drink.h"
#include "noalc.h"
#include "withalc.h"
#include "cart.h"
#include "account.h"
#include "payment.h"
#include "cashpayment.h"
#include "cardpayment.h"
#include "cout.h"




using namespace std;

//Cart::Cart(const vector<Drink*> &bauturi, float pret, const vector<float> &preturi): myDrinks(bauturi), price(pret), priceList(preturi) {}
//
//
//Cart::Cart(const Cart& cos): myDrinks(cos.myDrinks), price(cos.price), priceList(cos.priceList) {}


void Cart::productDelete(int index){    //pentru cand stergem un produs din cos, sa actualizam nr. de produse
    if (!myDrinks.empty() ) {
        //amount --;
        myDrinks.erase(myDrinks.begin() + index);
        price -= priceList[index];
    }
}

void Cart::setPaymentStrategy(Payment* strategy) {
    paymentStrategy = strategy;
}

void Cart::executePayment() {
    if (paymentStrategy) {
        paymentStrategy->pay(*this);
    } else {
        std::cout << "No payment strategy set." << std::endl;
    }
}



float Cart::cartPrice() const {
    return price;
}


vector<Drink*> Cart::getDrinks(Cart cart) {
    return cart.myDrinks;
}


Cart& Cart::operator=(const Cart& shopping) {
    if (this != &shopping) {
        this->myDrinks = shopping.myDrinks;
        this->price = shopping.price;
        this->priceList = shopping.priceList;
        this->paymentStrategy = shopping.paymentStrategy;
    }
    return *this;
}



std::ostream& operator<<(std::ostream& coutt, const Cart& cart) {
    coutt<<"Your shopping cart status:"<<endl;
    for (int x = 0; x < int(size(cart.myDrinks)); x++) {
        coutt << "Product "<<x + 1<<": "<< cart.myDrinks[x]->getDrinkName() << "  " << endl;
    }
    coutt << cart.price << endl;
    return coutt;
}


/*

void Cart::atAddressPayment(const Cart &cart) {
    short int input;
    cout << "Are you sure you want to pay at the delivery?" << endl;
    cout << "Press 1 for yes" << endl;
    cout << "Press 0 to switch to credit card payment" << endl;

    while (true) {
        cin >> input;
        try {
            if (input == 1) {
                cout << "You choose at delivery payment." << endl;
            }

            else {
                cout << "You switched to credit card payment!" << endl;
                creditCardInfo(cart);
            }
            cout << "Would you like to give a tip to the delivery person?" << endl;
            cout << "Press 1 for yes! :)" << endl;
            cout << "Press 0 for no!" << endl;
            cin >> input;
            if (input == 1) {
                cart.giveATip(cart);
                //Cout::orderAndExit();
            }
            else if (input == 0) {
                cout << "It's fine!" << endl;
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
} */



/*
void Cart::creditCardInfo(const Cart &cart) {
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
            //Cout::orderAndExit();
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
} */




float Cart::order(Cart &cart, vector<Drink*> coffeeMenu) {
    short int input, input2, inputDelete;
    bool appliedSale = false;
    Cout::menuText();
    NoAlc::menuOptions(coffeeMenu);
    do {
        try {
            std::cin >> input;
            if (input <= 20) {
                if (input != 20) {
                    if (input != 0) {
                        if (input >= int(coffeeMenu.size()) - 4) {
                            if (WithAlc::ageCheck()) {
                                Drink* bauturaUnsafe = new WithAlc(coffeeMenu[input - 1]->getDrinkName(), coffeeMenu[input - 1]->getDrinkPrice(), 0);
                                WithAlc* bauturica = dynamic_cast<WithAlc*>(bauturaUnsafe);

                                Drink *bauturaUnsafe2 = new WithAlc(coffeeMenu[input - 1]->getDrinkName(), coffeeMenu[input - 1]->getDrinkPrice(), bauturica->getAlc());
                                bauturaUnsafe2->description();

                                bauturaUnsafe->priceModifier();

                                myDrinks.push_back(coffeeMenu[input - 1]);
                                price += coffeeMenu[input - 1]->getDrinkPrice();
                                priceList.push_back(coffeeMenu[input - 1]->getDrinkPrice());

                                bauturica = nullptr;
                                bauturaUnsafe = nullptr;
                                bauturaUnsafe2 = nullptr;

                                delete bauturica;
                                delete bauturaUnsafe;
                                delete bauturaUnsafe;
                            } else {
                                std::cout << "We are sorry, but you are not eligible to buy alcoholic products! But you are still welcome to choose from our range of caffeinated drinks!" << std::endl;
                            }
                        } else {
                            Drink *bauturaSafe = coffeeMenu[input - 1];
                            bauturaSafe->description();
                            myDrinks.push_back(coffeeMenu[input - 1]);
                            price += coffeeMenu[input - 1]->getDrinkPrice();
                            priceList.push_back(coffeeMenu[input - 1]->getDrinkPrice());
                        }

                        std::cout << cart << std::endl;

                        if (cart.cartPrice() > 30) {
                            if (!appliedSale) {
                                std::cout << "You are now eligible for the sale! :)" << std::endl;
                                appliedSale = true;
                            } else {
                                appliedSale = false;
                            }
                            std::cout << "Cart Price with 25% off: "
                                      << cart.cartPrice() - Cout::priceCalculation(cart.cartPrice(), 25) << std::endl;
                        }
                    } else {
                        std::cout << "Are you sure you want to proceed to checkout?" << std::endl;
                        std::cout << "Press 1 to go back to editing your shopping cart!" << std::endl;
                        std::cout << "Press 0 to go to checkout" << std::endl;
                        std::cin >> input2;
                        if (input2 == 0) {
                            return cart.cartPrice();
                        } else if (input2 == 1) {
                            cart.order(cart, coffeeMenu);
                        } else {
                            throw std::invalid_argument("Your choice is invalid. Please try again!");
                        }
                    }
                } else {
                    std::cout << "Choose the index of the product that you would like to delete from your cart!";
                    std::cout << std::endl;
                    try {
                        do {
                            std::cin >> inputDelete;
                            if (inputDelete < int(getDrinks(cart).size())) {
                                cart.productDelete(inputDelete - 1);
                                std::cout << cart;
                                std::cout << "Press 0 if you want to proceed to payment" << std::endl;
                                std::cout << "If you want to continue to add/delete products from your cart, " << std::endl
                                          << "press on the index of the product from the menu!" << std::endl;
                            } else {
                                std::cout << "The product that you are trying to delete is not in your shopping cart. Please try again!" << std::endl;
                            }
                        }
                        while (inputDelete >= int(getDrinks(cart).size()));
                    }
                    catch (const std::exception &e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        std::cin.clear();
                    }
                }
            } else {
                throw std::invalid_argument("Your choice is invalid. Please try again!");
            }
        } catch (const std::exception &e) {
            input = 10;
            std::cerr << "Error: " << e.what() << std::endl;
            std::cin.clear();
        }
    } while (input != 0);
    return 0;



    /*
    short int input, input2, inputDelete;
    bool appliedSale = false;
    Cout::menuText();
    NoAlc::menuOptions(coffeeMenu);
    do {
        try {
            cin >> input;
            if (input <= 20) {
                if (input != 20) {
                    if (input != 0) {
                        if (input >= int(coffeeMenu.size()) - 4) {
                            if (WithAlc::ageCheck()) {
                                Drink* bauturaUnsafe = new WithAlc(coffeeMenu[input - 1] ->getDrinkName(), coffeeMenu[input - 1] ->getDrinkPrice(), 0);
                                WithAlc* bauturica = dynamic_cast<WithAlc*>(bauturaUnsafe);

                                Drink *bauturaUnsafe2 = new WithAlc(coffeeMenu[input - 1] ->getDrinkName(), coffeeMenu[input - 1] ->getDrinkPrice(), bauturica -> getAlc());
                                bauturaUnsafe2 -> description();


                                bauturaUnsafe -> priceModifier();

                                myDrinks.push_back(coffeeMenu[input - 1]);
                                price += coffeeMenu[input - 1]->getDrinkPrice();//productPrice;
                                priceList.push_back(coffeeMenu[input - 1]->getDrinkPrice());


                                bauturica = nullptr;
                                bauturaUnsafe = nullptr;
                                bauturaUnsafe2 = nullptr;

                                delete bauturica;
                                delete bauturaUnsafe;
                                delete bauturaUnsafe;

                            }

                            else {
                                cout << "We are sorry, but you are not elligible to buy alcoholic products! But you are still welcome to choose" << endl;
                                cout << "from our range of caffeinated drinks!" << endl;
                            }
                        }
                        else {
                            Drink *bauturaSafe = coffeeMenu[input - 1];
                            bauturaSafe->description();
                            myDrinks.push_back(coffeeMenu[input - 1]);
                            price += coffeeMenu[input - 1]->getDrinkPrice();//productPrice;
                            priceList.push_back(coffeeMenu[input - 1]->getDrinkPrice());
                        }


                        cout << cart << endl;



                        if (cart.cartPrice() > 30) {
                            if (!appliedSale) {
                                cout << "You are now eligible for the sale! :)" << endl;
                                appliedSale = true;
                            }
                            else {
                                appliedSale = false;
                            }
                            cout << "Cart Price with 25% off: "
                                 << cart.cartPrice() - Cout::priceCalculation(cart.cartPrice(), 25) << endl;

                        }

                    }
                    else {
                        cout << "Are you sure you want to proceed to checkout?" << endl;
                        cout << "Press 1 to go back to editing your shopping cart!" << endl;
                        cout << "Press 0 to go to checkout" << endl;
                        cin >> input2;
                        if (input2 == 0) {
                            return cart.cartPrice();
                        }

                        else if (input2 == 1) {
                            cart.order(cart, coffeeMenu);
                        }

                        else {
                            throw std::invalid_argument("Your choice is invalid. Please try again!");
                        }
                    }
                }
                else {
                    cout << "Choose the index of the product that you would like to delete from your cart!" << endl;
                    try {
                        do {
                            cin >> inputDelete;       //am gasit un produs pe care vrem sa il stergem & inputDelete retine al catelea produs sa fie sters;
                            if (inputDelete < int(getDrinks(cart).size())) {
                                cart.productDelete(inputDelete - 1);


                                cout << cart;


                                cout << "Press 0 if you want to proceed to payment" << endl;
                                cout << "If you want to continue to add/delete products from your cart, " << endl
                                     << "press on the index of the product from the menu!" << endl;
                            }

                            else {
                                cout << "The product that you are trying to delete is not in your shopping cart. Please try again!" << endl;
                            }
                        } while (inputDelete >= int(getDrinks(cart).size()));
                    }
                    catch (const std::exception &e) {
                        std::cerr << "Error: " << e.what() << std::endl;
                        cin.clear();
                    }
                }
            }
            else {
                throw std::invalid_argument("Your choice is invalid. Please try again!");
            }
        }
        catch (const std::exception &e) {
            input = 10;
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
        }
    }
    while (input != 0);
    return 0;
     */

}




void Cart::readyToOrder(Cart &cart, const vector<Drink*>& coffeeMenu) {
    short int input;
    Cout::textToFinish();
    while(true) {
        cin >> input;
        try {
            if (input == 1) {
                deliveryAddress(cart);
                cout << endl << "Choose one of the following payment options: " << endl;
                cout << "1: Credit Card" << endl;
                cout << "2: Cash on delivery" << endl;
                short int input2;
                cin >> input2;

//                Payment* paymentStrategy = nullptr;
//                Payment* localPaymentStrategy = nullptr;
                if (input2 == 1) {
                    paymentStrategy = new CreditCardPayment();
                } else if (input2 == 2) {
                    paymentStrategy = new AtAddressPayment();
                } else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }

                cart.setPaymentStrategy(paymentStrategy);

                cart.executePayment();

                delete paymentStrategy;
                delete paymentStrategy;

                cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)" << endl;
                break;
            } else if (input == 2) {
                order(cart, coffeeMenu);
                readyToOrder(cart, coffeeMenu);
                break;
            } else if (input == 0) {
                cout << "We are sorry to see you leave!" << endl;
                break;
            } else {
                throw std::invalid_argument("Your choice is invalid. Please try again!");
            }
        } catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
        }
    }
}


/*
void Cart::readyToOrder(Cart &cart, const vector<Drink*>& coffeeMenu) {
    short int input;
    Cout::textToFinish();
    while(true) {
        cin >> input;
        try {
            if (input == 1) {
                deliveryAddress(cart);
                cout << endl << "Choose one of the following payment options: " << endl;
                cout << "1: Credit Card" << endl;
                cout << "2: Cash on delivery" << endl;
                short int input2;
                cin >> input2;
                if (input2 == 1) {
                    creditCardInfo(cart);

                    cout << endl << "Are your sure you want to place the order?" << endl;
                    cout << "Press 1 to confirm the order! :D" << endl;
                    cout << "Press 2 to switch to cash on delivery payment!" << endl;
                    cout << "Press 3 to go back to editing your cart" << endl;
                    cout << "Press 0 to exit the app! :(" << endl;
                    cin >> input2;

                    if (input2 == 0) {
                        cout << "We are sorry that you are leaving!";
                        break;
                    }
                    else if (input2 == 1) {
                        cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
                        break;
                    }
                    else if (input2 == 2) {
                        atAddressPayment(cart);
                        break;
                    }
                    else if (input2 == 3) {
                        cart.order(cart, coffeeMenu);
                        readyToOrder(cart, coffeeMenu);
                        break;
                    }

                    else {
                        throw std::invalid_argument("Your choice is invalid. Please try again!");
                    }
                }
                else if (input2 == 2) {
                    atAddressPayment(cart);
                    break;
                }
                else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }

            }
            else {
                if (input == 2) {
                    order(cart, coffeeMenu);
                    readyToOrder(cart, coffeeMenu);
                    break;
                }
                else if (input == 0) {
                    cout << "We are sorry to see you leave!";
                    break;
                }
                else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }
            }
        }
        catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
        }
    }
} */



void Cart::deliveryAddress(const Cart &cart) {
    string address, zipCode;
    cout << "You are being redirected on the checkout page..." << endl;
    cout << "Subtotal: " << cart.cartPrice() << endl ;     //de aici urmeaza partea de checkout etc!!
    if (cart.cartPrice() >= 30) {
        cout << Cout::priceCalculation(cart.cartPrice(), 25) + cart.cartPrice() << endl;
    }
    else {
        cout << cart.cartPrice() << endl;
    }
    try {

        if (cart.cartPrice() > 0) {
            cout << "Our products do not support dropbox delivery! You will receive them through Doordash as soon as possible." << endl;
            cout << endl << "Introduce the delivery information!" << endl;
            cout << "Address: ";
            cin >> address;
            cout << endl << "Zip code: ";
            cin >> zipCode;
        }
    }
    catch (const std::exception& e) {
        cerr << "Your cart is empty. Please add products to it and return later " << e.what() << endl;
        cin.clear();
    }
}



void Cart::giveATip(const Cart &cart) const {
    short int input;
    float tip = 0;
    cout << "How much would you like to tip your delivery person?" << endl;
    cout << "Press 1 for 10%" << endl;
    cout << "Press 2 for 20%" << endl;
    cout << "Press 3 for 50%" << endl;
    cout << "Press 4 for 100%" << endl;
    cin >> input;

    switch (input) {
        case 1:
            tip = Cout::priceCalculation(cart.cartPrice(), 10);
            //percent = 10;
            break;
        case 2:
            tip = Cout::priceCalculation(cart.cartPrice(), 20);
            //percent = 20;
            break;
        case 3:
            tip = Cout::priceCalculation(cart.cartPrice(), 50);
            //percent = 50;
            break;
        case 4:
            tip = Cout::priceCalculation(cart.cartPrice(), 100);
            //percent = 100;
            break;
    }
    cout << "You will have to pay: " << tip + cart.cartPrice() << endl;
}


int Cart::everything(Cart cart, const vector<Drink*> &coffeeMenu) {
    cart.order(cart, coffeeMenu);
    cart.readyToOrder(cart, coffeeMenu);
    return 0;
}

Cart::~Cart() {};
