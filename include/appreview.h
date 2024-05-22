#ifndef OOP_APPREVIEW_H
#define OOP_APPREVIEW_H


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
    ReviewApp(std::map<std::string, T>* firstReview) : Review<T>(firstReview) {
        this -> caracteristici["Interface"] = T{};
        this -> caracteristici["Functionality"] = T{};
        this -> caracteristici["Payment"] = T{};
    }
    ReviewApp(const Review<T>& rev) : Review<T>(rev.getReview()) {
        this -> caracteristici["Interface"] = T{};
        this -> caracteristici["Functionality"] = T{};
        this -> caracteristici["Payment"] = T{};
    }



    void makeReviewApp(ReviewApp<T>* review, short int input) {
//        cout << "Here are other users' reviews:" << endl;
//        review -> printReviews();
        T opinie;
        float n1, n2, n3;
        cout << "Firstly, please grade our interface: " << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        if constexpr (std::is_arithmetic<T>::value) {
            if (opinie < 0 || opinie > 5) {
                review -> checkGrade(opinie);
            }
            caracteristici["Interface"] = opinie;
        }

        cout << "What about the overall functionality of the app?" << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        if constexpr (std::is_arithmetic<T>::value) {
            if (opinie < 0 || opinie > 5) {
                review -> checkGrade(opinie);
            }
            caracteristici["Functionality"] = opinie;
        }

        cout << "Last but not least, what would you say about our payment system?" << endl;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cin >> opinie;
        if constexpr (std::is_arithmetic<T>::value) {
            if (opinie < 0 || opinie > 5) {
                review -> checkGrade(opinie);
            }
            caracteristici["Payment"] = opinie;
        }

        cout << "Thank you for your time! Your review will help us improve our services in the future! Have a nice day!" << endl;
    }

};






#endif //OOP_APPREVIEW_H

