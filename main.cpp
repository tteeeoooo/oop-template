#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Drink{
private:
    string drinkChoice;       //tipul bauturii
    double price;              //pretul bauturii
public:
    //explicit Drink(string drinkName = "", float priceTag = 0) {}

    explicit Drink(const string &drinkName = "", double priceTag = 0): drinkChoice(drinkName), price(priceTag) {}

    //explicit Drink(const string &drinkName): drinkChoice(drinkName), price(0) {}

    //construcotri de initializare + supraincarcare

    Drink(const Drink &bauturica): drinkChoice(bauturica.drinkChoice), price(bauturica.price) {}

    Drink &operator=(const Drink &bauturica) {
        if (this != &bauturica) {
            this -> drinkChoice = bauturica.drinkChoice;
            this -> price = bauturica.price;
        }
        return *this;
    }

    friend Drink operator+(const Drink &bauturica, const Drink &menu) {
        Drink calcul;
        calcul.price = menu.price + bauturica.price;
        return calcul;
    }

    friend ostream& operator<<(ostream &coutt, const Drink &myDrink) {
        coutt<<myDrink.drinkChoice<<" "<<myDrink.price;
        return coutt;
    }
    //supraincarcarea operatorului de cout

    friend istream& operator>>(istream &cinn, Drink &myDrink) {
        cinn >> myDrink.drinkChoice >>myDrink.price;
        return cinn;
    }
    //supraincarcarea oepratorului din cin

    string getDrinkName() {
        return drinkChoice;
    }
    [[nodiscard]] double getDrinkPrice() const{
        return price;
    }

    ~Drink() = default;
};

double operator -(const Drink &bauturica, double procent) {
    double reducere = (bauturica.getDrinkPrice() * procent) / 100;
    return bauturica.getDrinkPrice() + reducere;
}


void menuText();

void menuOptions(vector<Drink> coffeeMenu);

float priceCalculation(float oldPrice, float sale);

class Cart{
private:
    vector<Drink> myDrinks;            //vector de bauturi din cos => neaparat sa invat cum functioneaza vectorii in C++!!!!
    //int amount;                         //nr de bauturi din cos
    float price;                        //suma care urmeaza sa fie platita
    vector<float> priceList;            //lista prteurilor

public:
    Cart(): myDrinks({}), price(0), priceList(0) {}


    explicit Cart(vector<Drink> &bauturi): myDrinks(bauturi), price(0) {}



    explicit Cart(float pret): myDrinks({}), price(pret) {}


    //pana aici au fost constructorii supraincarcati


    Cart(const Cart& cos): myDrinks(cos.myDrinks), price(cos.price), priceList(cos.priceList) {}


    void productAdd(const Drink &bautura) { //, float productPrice){       //pentru cand adaugam un produs in cos, sa actualizam nr. de produse
        //amount ++;
        myDrinks.push_back(bautura);
        price += bautura.getDrinkPrice();//productPrice;
        priceList.push_back(bautura.getDrinkPrice());
    };

    void productDelete(int index){    //pentru cand stergem un produs din cos, sa actualizam nr. de produse
        if (!myDrinks.empty() ) {
            //amount --;
            myDrinks.erase(myDrinks.begin() + index);
            price -= priceList[index];
        }
    }
    [[nodiscard]] float cartPrice() const {
        return price;
    }




    Cart& operator=(const Cart& shopping) {
        if (this != &shopping) {
            this->myDrinks = shopping.myDrinks;
            this->price = shopping.price;
            this->priceList = shopping.priceList;
        }
        return *this;
    }


    friend ostream& operator<<(ostream& coutt, const Cart& shopping) {
        coutt<<"Your shopping cart status:"<<endl;
        for (int x = 0; x < int(size(shopping.myDrinks)); x ++) {
            coutt << "Product "<<x + 1<<": "<<shopping.myDrinks[x] << "  " << endl;
        }
        coutt << shopping.price<<endl;
        return coutt;
    }

    ~Cart() = default;
};

class Account {
private:
    string userName;                //nume de utlizator
    string password;                //parola
public:
    void userRead() {
        cout << "Username: ";
        cin >> userName;
        cout << "Password: ";
        cin >> password;
        cout<<"Well hello "<<userName<<"! We are glad to have you back! :)"<<endl;
        cout<<"What would you like to do today? Choose one of the following options!"<<endl;
    }

    friend ostream& operator<<(ostream& COUT, const Account& acc) {
        COUT<< acc.userName;
        return COUT;
    }

    ~Account() = default;
};

void menuText();

void menuOptions(vector<Drink> coffeeMenu);

void underLine();

void upperLine();

float priceCalculation(float oldPrice, float sale);

float order(Cart &cart, vector<Drink> coffeeMenu);

void atAddressPayment(const Cart &cart);

void giveATip(const Cart &cart);

int textToFinish();

float orderAndExit() ;

void creditCardInfo(const Cart &cart);

void deliveryAddress(const Cart &cart);

int coutFinishedOrder();

void coutAbortedOrder();

void todaysSales();

int main() {
    Cart cart;
    Account user;
    vector<Drink> coffeeMenu = {Drink("Iced Latte", 5.9), Drink("Cold Brew", 3.9),
                                Drink("Matcha Latte", 6.5), Drink("Pink Drink Refresher", 4.6),
                                Drink("Vanilla Sweet Cream Cold Brew", 6.5), Drink("Vanilla Cremè", 5.5),
                                Drink("Cinnamon Caramel Cream Cold Brew", 4.0),
                                Drink("Cold Brew", 5.0), Drink("Caramel Ribbon Crunch Frappucino", 5.5),
                                Drink("Caramel Ribbon Crunch Frappucino", 7.0),
                                Drink("Oleato Golden Foam Iced Shaken Espresso With Toffeenut", 7.5),
                                Drink("Iced Matcha Tea Latte With Oatmilk", 6.5), Drink("Espresso", 3.0),
                                Drink("Caffè Americano", 3.5), Drink("Fiji Water", 3.3)};

    cout << "Chamberlain Coffee - Easy Mobile & Online Ordering & Delivery" << endl;
    todaysSales();

    cout << "Connect to your account: " << endl;
    user.userRead();
    //pana aici utilizatorul a introdus datele personale -> de cautat cum fac ca atunci cand utilizatorul scrie
    // de la tastatura sa apara * in loc de caracter??
    //update: nu merge cum trebuie!!!

    cout << "1: Menu" << endl;
    cout << "0: Exit" << endl << endl;
    cout << "Press 1 to see the menu / start adding products to your cart! :D" << endl;
    cout << "Press 0 to exit the app :(" << endl;
    short int input;
    cin >> input;
    if (input == 1) {
        while (input != 0) {
            order(cart, coffeeMenu);
            //finishOrder();
            textToFinish();
            cin >> input;

            if (input == 1) {
                deliveryAddress(cart);
                cout << endl << "Choose one of the following payment options: " << endl;
                cout << "1: Credit Card" << endl;
                cout << "2: Cash on delivery" << endl;
                cin >> input;
                if (input == 1) {
                    creditCardInfo(cart);

                    cout << endl << "Are your sure you want to place the order?" << endl;
                    cout << "Press 1 to confirm the order! :D" << endl;
                    cout << "Press 2 to switch to cash on delivery payment!" << endl;
                    cout << "Press 3 to go back to editing your cart" << endl;
                    cout << "Press 0 to exit the app! :(" << endl;
                    cin >> input;

                    if (input == 0) {
                        cout << "We are sorry that you are leaving!";
                        return 0;
                    } else {
                        if (input == 1) {
                            cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
                            return 0;
                        } else {
                            if (input == 2) {
                                atAddressPayment(cart);
                            } else {
                                if (input == 3) {
                                    order(cart, coffeeMenu);
                                } else {
                                    cout << "We are sorry that you are leaving!";
                                    return 0;
                                }
                            }
                        }
                    }
                } else {
                    if (input == 2) {
                        atAddressPayment(cart);
                    }
                    cout << "Press 1 to confirm the order!" << endl << "Press 0 to cancel and exit the app." << endl;
                    cin >> input;
                    if (input == 0) {
                        cout << "We are sorry that you are leaving!";
                    } else {
                        coutFinishedOrder();
                    }
                    return 0;
                }
            }

            if (input == 2) {
                order(cart, coffeeMenu);
            } else {
                if (input == 0) {
                    cout << "We are sorry to see you leave!";
                    return 0;
                }
            }
        }
        orderAndExit();

    }

    if (input == 0){
        return 0;
    }
    return 0;
}


float order(Cart &cart, vector<Drink> coffeeMenu) {
    short int input, input2, inputDelete;
    bool appliedSale = false;
    menuText();
    menuOptions(coffeeMenu);
    input = 1;
    while (input != 0) {
        cin >> input;
        if (input != 20) {
            if (input != 0) {
                cart.productAdd(coffeeMenu[input - 1]);//.drinkName(), coffeeMenu[input - 1].drinkPrice());
                cout << cart;
                if (cart.cartPrice() > 30) {
                    if (!appliedSale) {
                        cout << "You are now eligible for the sale! :)" << endl;
                        appliedSale = true;
                    }
                    else {
                        appliedSale = false;
                    }
                    cout<<"Cart Price with 25% off: " << priceCalculation(cart.cartPrice(), 25) << endl;
                }
            } else {
                cout << "Are you sure you want to proceed to checkout?" << endl;
                cout << "Press 1 to go back to editing your shopping cart!" << endl;
                cout << "Press 0 to go to checkout" << endl;
                cin >> input2;
                if (input2 == 0) {
                    return cart.cartPrice();
                }
                else {
                    order(cart, coffeeMenu);
                }
            }
        }
        else {
            cout << "Choose the index of the product that you would like to delete from your cart!" << endl;
            cin>> inputDelete;       //am gasit un produs pe care vrem sa il stergem & inputDelete retine al catelea produs sa fie sters;
            cart.productDelete(inputDelete - 1);
            cout << cart;
            cout << "Press 0 if you want to proceed to payment" << endl;
            cout << "If you want to continue to add/delete products from your cart, " << endl << "press on the index of the product from the menu!" << endl;
        }
    }
    return cart.cartPrice();
}


float priceCalculation(float oldPrice, float sale) {
    return (oldPrice * sale) / 100;
}

float orderAndExit() {
    short int input;
    cout <<endl << "Would you like to order your cart?" << endl;
    cout << "Press 1 to confirm!" << endl;
    cout << "Press 0 to exit! :(" << endl;
    cin >> input;
    if (input == 1) {
        coutFinishedOrder();
    }
    else {
        coutAbortedOrder();
    }
    return 0;
}

void menuText() {
    cout << "Choose the index of a product each time your want to add it to your cart! :D"<<endl;
    cout << "If you want to delete a product from your cart, press '20'." << endl;
    cout << "When you are done making your cart, just press 0! :)" << endl << endl;
}


void menuOptions(vector<Drink> coffeeMenu) {
    cout << endl << "Here are your options:" << endl;
    for (int x = 0; x < 15; x++) {
        cout << "Product " << x + 1 << ": " << coffeeMenu[x].getDrinkName() << " " << coffeeMenu[x].getDrinkPrice() << " " << endl;
    }
}

int textToFinish() {
    cout << endl << "Are you sure you don't want to edit your cart?" << endl;
    cout << "Press 1 to go introduce your delivery information!" << endl;
    cout << "Press 2 to go back to editing your cart!" << endl;
    cout << "Press 0 to exit :(" << endl;
    return 0;
}

void deliveryAddress(const Cart &cart) {
    string address;
    int zipCode;
    cout << "You are being redirected on the checkout page..." << endl;
    cout << "Subtotal: " << cart.cartPrice() << endl ;     //de aici urmeaza partea de checkout etc!!
    if (cart.cartPrice() >= 30) {
        cout<< priceCalculation(cart.cartPrice(), 25) + cart.cartPrice() << endl;
    }
    else {
        cout << cart.cartPrice() << endl;
    }
    cout << "Our products do not support dropbox delivery! You will receive them through Doordash as soon as possible." << endl;
    cout << endl << "Introduce the delivery information!" << endl;
    cout << "Address: ";
    cin >> address;
    cout << endl << "Zip code: ";
    cin >> zipCode;
}


void creditCardInfo(const Cart &cart) {
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
    if (input == 1) {
        giveATip(cart);
    }
    else {
        orderAndExit();
    }
//        orderAndExit();
//        cout << endl;
//    }
//    else {
//        cout << "Are you sure? :(" << endl;
//        cin >> input;
//        if (input == 0) {
//            cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
//            return ;
//        }
//        else {
//            Cart giveATip(cart);
//            orderAndExit();
//        }
//    }
}

void atAddressPayment (const Cart &cart) {
    short int input;
    cout << "Are you sure you want to pay at the delivery?" << endl;
    cout << "Press 1 for yes" << endl;
    cout << "Press 0 to switch to credit card payment" << endl;
    cin >> input;

    if (input == 1) {
        cout << "You choose at delivery payment." << endl;
    }
    else {
        cout << "You switched to credit card payment!" << endl;
        creditCardInfo(cart);
        return ;
    }
    cout << "Would you like to give a tip to the delivery person?" << endl;
    cout << "Press 1 for yes! :)" << endl;
    cout << "Press 0 for no!" << endl;
    cin >> input;
    if (input == 1) {
        giveATip(cart);
        orderAndExit();
    }
}

int coutFinishedOrder() {
    cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
    return 0;
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

void giveATip(const Cart &cart) {
    short int input;
    float tip = 0;
    cout << "How much would you like to tip your delivery person?" << endl;

    cout << "Press 1 for 10%" << endl;
    cout << "Press 2 for 20%" << endl;
    cout << "Press 3 for 50%" << endl;
    cout << "Press 4 for 100%" << endl;
    cout << "Press 0 to skip" << endl;
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

