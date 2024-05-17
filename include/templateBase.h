#include <iostream>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

class Account;

class Drink;

class Cart;

template <typename T>
class Review {
protected:
    std::map<std::string, T> review;    //aici e review-ul (sub forma de nota/notita) general

public:
    Review();

    explicit Review(const string& cheie = "", const T& valoare = T{}) {
        review[cheie] = valoare;
    }

    const std::map<std::string, T>& getReview();

    //void addReview(const std::string& Name, const T &valoare);

    void printReviews();

    virtual void makeReview(Review<T>& review, const Account& user);

    void checkGrade(const T &grade);

    bool checkWords(std::string &note);

    void sortLambda(Review<T>& reviewSituation);

    ~Review() = default;
};
