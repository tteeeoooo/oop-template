#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>

using namespace std;

class Account {
private:
    static std::unique_ptr<Account> instance;

    string userName;
    string password;
    explicit Account(const string &nume = "", const string &parola = ""): userName(nume), password(parola){};
public:
    static Account* getInstance(const std::string& user = "", const std::string& pass = "");

    static Account* obiectNou();

    string getName() const;

    int exc();
    void userRead();
    void premiumText();
    void inputData();

    string inputVisual(short int input);
    void upgrade();
    virtual void save();

    std::ostream& operator<<(std::ostream& coutt) const;
    std::istream& operator>>(std::istream& cinn);

    ~Account();
};

#endif // ACCOUNT_H
