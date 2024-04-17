#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>


using namespace std;

class WithAlc: public Drink {
private:
    int alcohol;
public:
    explicit WithAlc(const string &nume = "", const double &pret = 0, const int &alc = 0);
    WithAlc(const WithAlc &notGood);
    void setAlc(int percent);

    void description() const override;
    int getAlc() const;
    double priceModifier() const override;
    static bool ageCheck();

    std::ostream& operator<<(std::ostream& coutt) override;
    std::istream& operator>>(std::istream& cinnn);
    WithAlc& operator=(const WithAlc& hydratingg);

    virtual ~WithAlc();
};
