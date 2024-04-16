#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>


using namespace std;



class NoAlc: public Drink {
private:
    int calories;
public:
    explicit NoAlc(const string &nume = "", const double &pret = 0, const int &calorii = 0);
    NoAlc(const NoAlc &notGood);
    void description() const override;
    int getCalories() const;
//    virtual void setAlc(int percent) const = 0;
    double priceModifier() const override;

    std::ostream& operator<<(std::ostream& coutt) override;
    std::istream& operator>>(std::istream& cinn);
    NoAlc& operator=(const NoAlc& hydrating);

    virtual ~NoAlc();
};

