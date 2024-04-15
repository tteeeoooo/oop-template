
#include "poo.h"


Drink::Drink(string drinkName, const double &priceTag): drinkChoice(std::move(drinkName)), price(priceTag) {}

Drink::Drink(const Drink &bauturica) = default;

Drink& Drink::operator=(const Drink &bauturica) {
    if (this != &bauturica) {
        this -> drinkChoice = bauturica.drinkChoice;
        this -> price = bauturica.price;
    }
    return *this;
}


void Drink::description() const {};


double Drink::priceModifier() const {
    return price;
}


std::ostream& Drink::operator<<(std::ostream& coutt) const {
    coutt<< drinkChoice<<" "<< price;
    return coutt;
}




string Drink::getDrinkName() {
    return drinkChoice;
}

double Drink::getDrinkPrice() const{
    return price;
}


void Drink::menuOptions(vector<Drink*> coffeeMenu) {
    cout << endl << "Here are your options:" << endl;
    for (int x = 0; x < int(coffeeMenu.size()); x++) {
        cout << "Product " << x + 1 << ": " << coffeeMenu[x]->getDrinkName() << " - price with 19% TVA: " << coffeeMenu[x] -> priceModifier() << " " << endl;
    }
}


Drink::~Drink() {}

double operator -(const Drink &bauturica, double procent) {
    double reducere = (bauturica.getDrinkPrice() * procent) / 100;
    return bauturica.getDrinkPrice() + reducere;
}




NoAlc::NoAlc(const string &nume, const double &pret, const int &calorii): Drink(nume, pret), calories(calorii) {};

    //NoAlc(string nume, double pret, int calorii): Drink(nume, pret), calories(calorii) {};

NoAlc::NoAlc(const NoAlc& notGood) = default;


void NoAlc::description() const {
    cout << "This drink contains " << NoAlc::getCalories() << " calories!" << endl;
}


int NoAlc::getCalories() const {
    return calories;
}

double NoAlc::priceModifier() const {
    return price + (price * 19) / 100;
}



std::ostream& NoAlc::operator<<(std::ostream& coutt) const {
    coutt << drinkChoice << " " << price << " " << calories;
    return coutt;
}

std::istream& NoAlc::operator>>(std::istream& cinn) {
    cinn >> drinkChoice >> price;
    return cinn;
}


//std::istream& NoAlc::operator>>(std::istream& cinn) {
//    cinn >> drinkChoice >> price >> calories;
//    return cinn;
//}


//    calorieCalc(const vector <NoAlc>& drinkities)


NoAlc& NoAlc::operator=(const NoAlc& hydrating) {
    if (this != &hydrating) {
        drinkChoice = hydrating.drinkChoice;
        price = hydrating.price;
        calories = hydrating.calories;
    }
    return *this;
}


NoAlc::~NoAlc() = default;



WithAlc::WithAlc(const string &nume, const double &pret, const int &alc): Drink(nume, pret), alcohol(alc) {};

   // WithAlc(string nume, double pret, int alc): Drink(nume, pret), alcohol(alc) {};

WithAlc::WithAlc(const WithAlc& notGood) = default;

void WithAlc::setAlc(int percent) {
    alcohol = percent;
}


void WithAlc::description() const  {
    cout << "This drink contains alcohol in a percentage of " << WithAlc::getAlc() << "%" << endl;
}

int WithAlc::getAlc() const {
    return alcohol;
}


double WithAlc::priceModifier() const {
    double p = price + (price * 19) / 100;
    return p + p / 20;
}   //returneaza pretul cu tva + acciza de 5% pe bauturile alcoolice




bool WithAlc::ageCheck() {
    short int input;
    cout << "Please enter your age: ";
    try {
        cin >> input;
        if (!std::cin.fail()) {
            if (input < 21) {
                return false;
            }
            else {
                cout << "You can have access to alcoholic drinks!" << endl;
                cout << "Side note: according to the Romanian regulations regarding selling fo alcoholic drinks, you will be imposed with a 5% excise tax!" << endl;
                return true;
            }
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



//friend ostream& WithAlc::operator<<(ostream &coutt, const WithAlc &myDrink) {
//    coutt << myDrink.drinkChoice << " " << myDrink.price << myDrink.alcohol;
//    return coutt;
//}

std::ostream& WithAlc::operator<<(std::ostream& coutt) const {
    coutt << drinkChoice << " " << price << alcohol;
    return coutt;
}


std::istream& WithAlc::operator>>(std::istream& cinn) {
    cinn >> drinkChoice >> price >> alcohol;
    return cinn;
}



WithAlc& WithAlc::operator=(const WithAlc& hydrating) {
    if (this != &hydrating) {
        drinkChoice = hydrating.drinkChoice;
        price = hydrating.price;
        alcohol = hydrating.alcohol;
    }
    return *this;
}


WithAlc::~WithAlc() = default;




Account::Account(const std::string &nume, std::string parola): userName(nume), password(std::move(parola)) {}

Account::Account(const Account& cont): userName(cont.userName), password(cont.password) {}

string Account::getName() const {
    return userName;
}


void Account::exc() {
    short int input;
    while (true) {
        cin >> input;
        try {
            if (input == 1) {
                cout << "Secret code: ";
                break;
            }
            else if (input == 2) {
                cout << "Password: ";
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


void Account::userRead() {
    short int input;
    cout << "Username: ";
    cin >> userName;
    cout << "If you do not remember your password and want to enter your secret code, press 1; for password, press 2" << endl;
    exc();

    cin >> password;
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
                    premiumText();
                    upgrade();
                    break;
                }
                else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }
            }
            else if (input == 1){
                premiumText();
                upgrade();
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
        premiumText();
        cin >> input;
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
                    cout << tip;
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

    Account::~Account() {
        //std::cout << "Merge destructorul pentru account! :) \n";
    }



Cart::Cart(const vector<Drink*> &bauturi, float pret, const vector<float> &preturi): myDrinks(bauturi), price(pret), priceList(preturi) {}

Cart::Cart(const Cart& cos) = default; //: myDrinks(cos.myDrinks), price(cos.price), priceList(cos.priceList) {}

void Cart::productDelete(int index){    //pentru cand stergem un produs din cos, sa actualizam nr. de produse
    if (!myDrinks.empty() ) {
        //amount --;
        myDrinks.erase(myDrinks.begin() + index);
        price -= priceList[index];
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
    }
    return *this;
}


//ostream& Cart::operator<<(ostream& coutt) {
//    coutt<<"Your shopping cart status:"<<endl;
//    for (int x = 0; x < int(size(myDrinks)); x++) {
//        coutt << "Product "<<x + 1<<": "<< myDrinks[x]->getDrinkName() << "  " << endl;
//    }
//    coutt << price<<endl;
//    return coutt;
//}

std::ostream& operator<<(std::ostream& coutt, const Cart& cart) {
    coutt<<"Your shopping cart status:"<<endl;
    for (int x = 0; x < int(size(cart.myDrinks)); x++) {
        coutt << "Product "<<x + 1<<": "<< cart.myDrinks[x]->getDrinkName() << "  " << endl;
    }
    coutt << cart.price << endl;
    return coutt;
}



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
            } else {
                cout << "You switched to credit card payment!" << endl;
                creditCardInfo(cart);
            }
            cout << "Would you like to give a tip to the delivery person?" << endl;
            cout << "Press 1 for yes! :)" << endl;
            cout << "Press 0 for no!" << endl;
            cin >> input;
            if (input == 1) {
                cart.giveATip(cart);
                orderAndExit();
            }
            else if (input == 0) {
                orderAndExit();
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
        }
        else if (input == 0){
            orderAndExit();
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


float Cart::order(Cart &cart, vector<Drink*> coffeeMenu) {
    short int input, input2, inputDelete;
    bool appliedSale = false;
    menuText();
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
                                if (bauturica) {
                                    Drink *bauturaUnsafe2 = new WithAlc(coffeeMenu[input - 1] ->getDrinkName(), coffeeMenu[input - 1] ->getDrinkPrice(), bauturica -> getAlc());
                                    bauturaUnsafe2 -> description();
                                }


                                //bauturaUnsafe -> WithAlc::setAlc(coffeeMenu[input - 1] -> getAlc());
                                bauturaUnsafe -> priceModifier();
                                //WithAlc* bauturaAlc = dynamic_cast<WithAlc*>(bauturaUnsafe);
                                delete bauturaUnsafe;
                                //price += price2->priceModifier();
                                priceList.push_back(coffeeMenu[input - 1]->getDrinkPrice());
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

                        cout << "Nu stiu ce are varul asta!" << endl;
                        cout << cart << endl;
                        cout << "bandit" << endl;


                        if (cart.cartPrice() > 30) {
                            if (!appliedSale) {
                                cout << "You are now eligible for the sale! :)" << endl;
                                appliedSale = true;
                            }
                            else {
                                appliedSale = false;
                            }
                            cout << "Cart Price with 25% off: "
                                 << cart.cartPrice() - priceCalculation(cart.cartPrice(), 25) << endl;

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
}



void Cart::readyToOrder(Cart &cart, const vector<Drink*>& coffeeMenu) {
    short int input;
    textToFinish();
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
}


void Cart::deliveryAddress(const Cart &cart) {
    string address, zipCode;
    cout << "You are being redirected on the checkout page..." << endl;
    cout << "Subtotal: " << cart.cartPrice() << endl ;     //de aici urmeaza partea de checkout etc!!
    if (cart.cartPrice() >= 30) {
        cout<< priceCalculation(cart.cartPrice(), 25) + cart.cartPrice() << endl;
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
            tip = priceCalculation(cart.cartPrice(), 10);
            //percent = 10;
            break;
        case 2:
            tip = priceCalculation(cart.cartPrice(), 20);
            //percent = 20;
            break;
        case 3:
            tip = priceCalculation(cart.cartPrice(), 50);
            //percent = 50;
            break;
        case 4:
            tip = priceCalculation(cart.cartPrice(), 100);
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


Cart::~Cart() {}




int main() {
    Cart cart({}, 0, {});
    Account user;
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


    cout << "Café de Flore - Easy Mobile & Online Ordering & Delivery" << endl;
    todaysSales();

    cout << "Connect to your account: " << endl;
    user.userRead();

    cout << "Well hello " << user.getName() << "! We are glad to have you back! :)" << endl;
    cout << "What would you like to do today? Choose one of the following options!" << endl;
    cout << "1. Menu" << endl;
    cout << "0. Exit" << endl;


    while(true) {
        try {
            cin >> input;
            if (input == 0) {
                cout << "Are you sure you want to exit the app?" << endl;
                cout << "Press 1 to go back to order" << endl;
                cout << "Press 0 to exit" << endl;
                cin >> input;

                if (input == 0) {
                    cout << "We are sorry to see you leave! We hope you will come back soon!" << endl;
                    return 0;
                }
                else if (input == 1){
                    Cart::everything(cart, menu);
//                    cart.order(reinterpret_cast<Cart &>(cart), menu);
//                    cart.readyToOrder(reinterpret_cast<Cart &>(cart), menu);
                    return 0;
                }
                else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }
            }
            else {
                Cart::everything(cart, menu);
//                cart.order(reinterpret_cast<Cart &>(cart), menu);
//                cart.readyToOrder(reinterpret_cast<Cart &>(cart), menu);
                break;
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            cin.clear();
            return 0;
        }
    }
    return 0;
}



float priceCalculation(const float oldPrice, const float sale) {
    return (oldPrice * sale) / 100;
}


void orderAndExit() {
    short int input;
    cout <<endl << "Would you like to order your cart?" << endl;
    cout << "Press 1 to confirm!" << endl;
    cout << "Press 0 to exit! :(" << endl;
    while (true) {
        cin >> input;
        try {
            if (input == 1) {
                coutFinishedOrder();
                break;
            }
            else if (input == 0) {
                coutAbortedOrder();
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



void menuText() {
    cout << "Choose the index of a product each time your want to add it to your cart! :D"<<endl;
    cout << "If you want to delete a product from your cart, press '20'." << endl;
    cout << "When you are done making your cart, just press 0! :)" << endl << endl;
}


int textToFinish() {
    cout << endl << "Are you sure you don't want to edit your cart?" << endl;
    cout << "Press 1 to go introduce your delivery information!" << endl;
    cout << "Press 2 to go back to editing your cart!" << endl;
    cout << "Press 0 to exit :(" << endl;
    return 0;
}


void coutFinishedOrder() {
    cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
}


void coutAbortedOrder() {
    cout << "We are sorry that you are leaving! See you next time!";
}


void todaysSales() {
    cout << "Here is today's deal!" << endl;
    underLine();
    cout << "25% off for orders over $30" << endl;
    upperLine();
}


void underLine() {
    for (int i = 0; i < 30; i ++) {
        cout << "_";
    }
    cout << endl;
}


void upperLine() {
    for (int i = 0; i < 30; i ++) {
        cout << "‾";
    }
    cout<<endl;
}

