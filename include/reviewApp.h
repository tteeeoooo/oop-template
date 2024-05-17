#include <iostream>
#include <map>
#include <string>
#include <unordered_set>

using namespace std;

class Account;

template<typename T>
class Review;

template <typename T>
class ReviewApp: public Review<T> {
private:
    std::map<string, T> caracteristici;
public:
    ReviewApp() {
        Review("", "0");
        caracteristici["App name"] = "Chamberlain Coffee";
        caracteristici["Version"] = "3.0";
        caracteristici["Author"] = "Teodora Alexandra Nitu";
        caracteristici["Interface"] = "";
        caracteristici["Functionality"] = "";
        caracteristici["Payment"] = "";
    }

    void makeReviewApp(ReviewApp review, const Account& user);

};









































#ifndef OOP_REVIEWAPP_H
#define OOP_REVIEWAPP_H

#endif //OOP_REVIEWAPP_H
