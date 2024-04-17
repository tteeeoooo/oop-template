#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Account {
protected:
    string userName;
    string password;
public:
    explicit Account(const string &nume = "", string parola = "");
    Account(const Account &cont);
    string getName() const;

    int exc();
    void userRead();
    void premiumText();
    void inputData();

    string inputVisual(short int input);
    void upgrade();
    virtual void save();

    Account& operator=(const Account &acesta);
    std::ostream& operator<<(std::ostream& coutt) const;
    std::istream& operator>>(std::istream& cinn);

    virtual ~Account();
};
