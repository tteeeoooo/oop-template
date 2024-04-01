#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
using namespace std;


class Cart;
class Drink;
class Account;
class EditAccount;
class CreateAccount;


void menuText();

float priceCalculation(const float oldPrice, const float sale);

void underLine();

void upperLine();

int textToFinish();

float orderAndExit() ;

void coutFinishedOrder();

void coutAbortedOrder();

void todaysSales();



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

    static void menuOptions(vector<Drink> coffeeMenu) {
        cout << endl << "Here are your options:" << endl;
        for (int x = 0; x < 15; x++) {
            cout << "Product " << x + 1 << ": " << coffeeMenu[x].getDrinkName() << " " << coffeeMenu[x].getDrinkPrice() << " " << endl;
        }
    }

    ~Drink() = default;
};

double operator -(const Drink &bauturica, double procent) {
    double reducere = (bauturica.getDrinkPrice() * procent) / 100;
    return bauturica.getDrinkPrice() + reducere;
}

class Account {
protected:
    string userName;
    string password;

public:
    explicit Account(const string &nume = "", const string &parola = ""): userName(nume), password(parola) {}

    const string getName() {
        return userName;
    }

    const string getPassword() {
        return password;
    }

    void userRead() {
        short int input;
        cout << "Username: ";
        cin >> userName;
        cout << "If you do not remember your password and want to enter your secret code, press 1; for password, press 2" << endl;
        cin >> input;
        if (input == 2) {
            cout << "Password: ";
        }
        else {
            cout << "Secret code: ";
        }
        cin >> password;
        save("fisier1.txt");
    }

    virtual void save(const string &fileName) {
        ofstream f(fileName);
        if (!f.fail()) {
            if (f.is_open()) {
                f << userName << endl << password;
                f.close();
            }
        }
    }       // se scriu numele si parola in fisier


    Account& operator=(const Account& account) {
        if (this != &account) { // Verificare auto-atribuire
            userName = account.userName;
            password = account.password;
        }
        return *this;
    }


    friend ostream& operator<<(ostream& COUT, const Account& acc) {
        COUT<< acc.userName;
        return COUT;
    }


    ~Account() = default;
};

class EditAccount: public Account{
private:
    string newPassword;
public:
    explicit EditAccount(const string &name = "", const string &oldPassword = "", const string &newpassword = ""): Account(name, oldPassword), newPassword(newpassword) {}


//    friend istream& operator>>(istream &cinn, Drink &myDrink) {
//        cinn >> myDrink.drinkChoice >>myDrink.price;
//        return cinn;
//    }



    EditAccount(const Account &cont, const string &parola): Account(cont), newPassword(parola) {}

    const string getNewPassword() {
        return newPassword;
    };

    static void modificaDatele(Account user, const string fileName) {
        string nume, parola, parolaNoua;
        nume = user.getName();
        parola = user.getPassword();
        ofstream f(fileName);
        if (f.is_open()) {
            cout << "Introduce the new password: " << endl;
            cin >> parolaNoua;
            EditAccount cont(nume, parola, parolaNoua);
            f << cont.getName() << endl << cont.getNewPassword();
            f.close();
        }
        else {
            cout << "Your changes could not be saved. Please come back later";
        }
    }

    EditAccount& operator=(const EditAccount& account) {
        if (this != &account) { // Verificare auto-atribuire
            userName = account.userName;
            password = account.password;
            newPassword = account.newPassword;
        }
        return *this;
    }



    ~EditAccount() = default;
};

class CreateAccount: public Account {
private:
    string secretCode;
    string email;
public:
    //CreateAccount(const string nume, const string parola, const string cod, const string mail): Account(nume, parola), secretCode(cod), email(mail) {}

    CreateAccount(): Account("", ""), secretCode(""), email("") {}


//    const string getSecretCode() {
//        return secretCode;
//    }
//
//    const string getEmail() {
//        return email;
//    }

    void create() {
        //short int input;
        cout << "Username: ";
        cin >> userName;
        cout << "Password: ";
        cin >> password;
        save("fisier1.txt");
        cout << "Please select a secret code to use in case you do not remember your password." << endl;
        cout << "Warning: this secret code cannot be changed, so please: do not forget it!" << endl;
        cin >> secretCode;
        cout << "Introduce your email: ";
        cin >> email;
        save("tastatura.txt");
    }

    void save(const string &fileName) override{
        ofstream f(fileName);
        if (!f.fail()) {
            if (f.is_open()) {
                f << userName << endl << password << endl << secretCode << endl << email;
                f.close();
            }
        }
    }

    CreateAccount& operator=(const CreateAccount& account) {
        if (this != &account) { // Verificare auto-atribuire
            userName = account.userName;
            password = account.password;
            secretCode = account.secretCode;
            email = account.email;
        }
        return *this;
    }


    ~CreateAccount() = default;
};



class Cart{
private:
    vector<Drink> myDrinks;            //vector de bauturi din cos => neaparat sa invat cum functioneaza vectorii in C++!!!!
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

    void atAddressPayment(const Cart &cart) {
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
        }
        cout << "Would you like to give a tip to the delivery person?" << endl;
        cout << "Press 1 for yes! :)" << endl;
        cout << "Press 0 for no!" << endl;
        cin >> input;
        if (input == 1) {
            cart.giveATip(cart);
            orderAndExit();
        }
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
            cart.giveATip(cart);
        }
        else {
            orderAndExit();
        }
    }


    float order(Cart &cart, const vector<Drink> &coffeeMenu) {
        short int input, input2, inputDelete;
        bool appliedSale = false;
        menuText();
        Drink::menuOptions(coffeeMenu);
        do {
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
                        cout<<"Cart Price with 25% off: " << cart.cartPrice() - priceCalculation(cart.cartPrice(), 25) << endl;
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
                    else {
                        cart.order(cart, coffeeMenu);
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
        while (input != 0);
        return 0;
        //return cart.cartPrice();
    }


    void readyToOrder(Cart &cart, const vector<Drink> &coffeeMenu) {
        short int input;
        textToFinish();
        cin >> input;

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
                }
                else {
                    if (input2 == 1) {
                        cout << "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)";
                    }
                    else {
                        if (input2 == 2) {
                            atAddressPayment(cart);
                        }
                        else {
                            if (input2 == 3) {
                                cart.order(cart, coffeeMenu);
                                readyToOrder(cart, coffeeMenu);
                            }
                            else {
                                cout << "We are sorry that you are leaving!";
                            }
                        }
                    }
                }
            }
            else {
                if (input2 == 2) {
                    atAddressPayment(cart);
                }
                cout << "Press 1 to confirm the order!" << endl << "Press 0 to cancel and exit the app." << endl;
                cin >> input2;
                if (input2 == 0) {
                    cout << "Have a good day! :)";
                    //return 0;
                }
                else {
                    coutFinishedOrder();
                    //return 0;
                }
            }
        }
        else {
            if (input == 2) {
                order(cart, coffeeMenu);
                readyToOrder(cart, coffeeMenu);
            }
            else {
                if (input == 0) {
                    cout << "We are sorry to see you leave!";
                }
            }
        }
    }


    static void beginningCout(Account &user, Cart cart, const vector<Drink> &coffeeMenu) {
        short int input;
        Account *me = new EditAccount();
        me = &user;
        cout << "1: Menu" << endl;
        cout << "2: Change your password!" << endl;
        cout << "0: Exit" << endl << endl;
        cout << "Press 1 to see the menu / start adding products to your cart! :D" << endl;
        cout << "Press 2 to change your password!" << endl;
        cout << "Press 0 to exit the app :(" << endl;
        cin >> input;
        if (input == 1) {
            Cart::everything(cart, coffeeMenu);
        }
        else {
            if (input == 2) {
                EditAccount::modificaDatele(*me, "fisier.txt");
                cout << "Your password was changed successfully!" << endl;
                beginningCout(user, cart, coffeeMenu);
            }
            else {
                cout << "We are sorry to see your leave. Hope to see you soon!";
            }
        }
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


    void giveATip(const Cart &cart) const {
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


    static void everything(Cart cart, const vector<Drink> &coffeeMenu) {
        cart.order(cart, coffeeMenu);
        cart.readyToOrder(cart, coffeeMenu);
    }   //fac cosul gen

    ~Cart() = default;
};



int main() {
    const Cart cart;
    short int input;
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

    cout << "Do you have an account? Press 1 to access it!" << endl;
    cout << "If you don't have one, it's ok! You can create one now & enjoy our products! Press 2 to create one." << endl;
    cin >> input;
    if (input == 1) {
        Account* user = new CreateAccount();
        cout << "Connect to your account: " << endl;
        user -> userRead();
        cout<<"Well hello "<< user -> getName() <<"! We are glad to have you back! :)"<<endl;
        cout<<"What would you like to do today? Choose one of the following options!"<<endl;
        Cart::beginningCout(*user, cart, coffeeMenu);
    }
    if (input == 2) {
            CreateAccount user;
            user.create();
            cout<<"What would you like to do today? Choose one of the following options!"<<endl;
            Cart::beginningCout(user, cart, coffeeMenu);
    }
    else {
        do {
            cout << "Your input is invalid. Please press again!";
            cin >> input;
            if (input == 1 || input == 2) {
                break;
            }
        } while (true);
        if (input == 1) {
            Account *user = new CreateAccount();
            cout << "Connect to your account: " << endl;
            user->userRead();
            cout << "Well hello " << user->getName() << "! We are glad to have you back! :)" << endl;
            cout << "What would you like to do today? Choose one of the following options!" << endl;
            Cart::beginningCout(*user, cart, coffeeMenu);
        }
        if (input == 2) {
            CreateAccount user;
            user.create();
            cout << "What would you like to do today? Choose one of the following options!" << endl;
            Cart::beginningCout(user, cart, coffeeMenu);
        }
    }
//    if (input == 1) {
//        Cart::everything(cart, coffeeMenu);     //practic face toata comanda
//    }
    return 0;
}


float priceCalculation(const float oldPrice, const float sale){
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
        return 0;
    }
    else {
        coutAbortedOrder();
        return 0;
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


