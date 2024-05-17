#include <iostream>
#include <map>
#include <string>
#include <unordered_set>
#include <cctype>
#include <algorithm>

using namespace std;

class Account;

class Drink;

class Cart;

template<typename T>
class Review;

template <typename T>
class ReviewProduct: public Review<T> {
private:
    std::map<std::string, T>categories;

public:
    ReviewProduct(const std::map<std::string, T>& firstReview)  {
        review(firstReview);
        categories["Taste"] = "0";
        categories["Packaging"] = "0";
        categories["Price-Quality Ratio"] = "0";
        categories["Adverse Effects"] = "0";
        categories["Recommendations"] = "0";
        //deci: indiferent ca vrea sa dea nota sau descriere, utilizatorul va avea, pentru bauturile non-alcoolice, categoriile
        //astea, adica primele 5, iar dupa la overall va pune o chestie generala legata de intregul aspect
    }

    ReviewProduct(const T& productId, const std::string& description) : Review<T>(productId, description) {};

    void makeReviewProduct(ReviewProduct review, const Account& user, Cart cart);


    bool checkDrinkList(vector<Drink*> bauturi, const string& drinkName);
};

