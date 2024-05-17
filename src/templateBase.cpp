#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include "templateBase.h"
#include "reviewapp.h"
#include "reviewDrink.h"
#include "account.h"
#include "cart.h"
using namespace std;




template<typename T>
void Review<T>::printReviews() {
    std::ifstream f("fisier1.txt"); //fisierul care contine review-uri pentru aplicatie
    if (!f.is_open()) {
        std::cerr << "Unable to open file fisier.txt" << std::endl;
        return;
    }
    cout << "Reviews for this product:" << std::endl;
    string user, reviewText;


    while (f >> user >> reviewText) {
        review[user] = reviewText;
    }
    f.close();

    std::sort(review.begin(), review.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    for (const auto& parere : review) {
        cout << parere.first << endl << parere.second;
        cout << endl << endl;
    }

}

template<typename T>
void Review<T>::makeReview(Review<T>& review, const Account& user) {
    short int input;
    try {
        cin >> input;
        if (input == 1) {    //pentru review la aplicatie
            ReviewApp<T>* appReview = dynamic_cast<ReviewApp<T>*>(&review);
//            static_cast<T*>(this)->makeReview();
//            const ReviewApp<T> *appReview = dynamic_cast<const ReviewApp<T> *>(&review);
            if (appReview) {
                makeReviewApp(input, appReview, user);
//                appReview->makeReview(input, review, user);
            }

            else {
                cout << "We could not continue with your review. We are sorry. Try again later" << endl;
            }
        }

        else {
            if (input == 2) {
                ReviewProduct<T>* productReview = dynamic_cast<ReviewProduct<T>*>(&review);
                if (productReview) {
                    makeReviewProduct(input, productReview, user);
//                appReview->makeReview(input, review, user);
                }
                else {
                    cout << "We could not continue with your review. We are sorry. Try again later" << endl;
                }
            }
            else {
                throw std::invalid_argument("Your choice is invalid. Please try again!");
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        cin.clear();
    }
}

template<typename T>
void Review<T>::checkGrade(const T &grade) {
    if (float(grade) < 0) {
        grade = 0;
    }
    else {
        if (float(grade) > 5) {
            grade = 5;      //daca se introduce o nota care nu e intre 0 si 5, aceasta devine automat cea mai apropiata de limita
        }
        else {
            if (grade - floor(grade) < 0.5) {
                grade = int(floor(grade));

            }
            else {
                grade = int(ceil(grade));
            }
            cout << "Thank you for your grade: " << endl;
            for (int i = 0; i < grade; i++) {
                cout << "⭑";
            }
            cout << endl;
        }
    }
}

template<typename T>
bool Review<T>::checkWords(std::string &note) {
    std::unordered_set<std::string> uglyWords_ = {
            "vulgar", "insult", "racism", "sexism", "homophobia",
            "violence", "explicit", "offensive", "profanity", "harassment",
            "discrimination", "threatening", "obscene", "abusive", "disrespectful",
            "derogatory", "disgusting", "inappropriate", "unacceptable",
            "blasphemy", "idiot", "bleah","ew", "uh", "wtf"
    };
    for (const auto& word : uglyWords_) {
        if (note.find(word) != std::string::npos) {
            return true;
        }
    }
    return false;
}

template<typename T>
void Review<T>::sortLambda(Review<T>& reviewSituation) {
    if constexpr (std::is_same_v<T, float>) {
        std::vector<std::pair<std::string, T>> reviewsVector(reviewSituation.reviews.begin(), reviewSituation.reviews.end());

        std::sort(reviewsVector.begin(), reviewsVector.end(),
                  [](const std::pair<std::string, T>& review1, const std::pair<std::string, T>& review2) {
                      return review1.second < review2.second;
                  });

        reviewSituation.reviews.clear();
        for (const auto& review : reviewsVector) {
            reviewSituation.reviews.insert(review);
        }
    }
}

//template <typename T>
//friend std::ostream& operator<<(std::ostream& coutt, const Review<T>& reviewCout) {
//    for (const auto& harta : reviewCout.review) {
//        coutt << harta.first << " " << harta.second << endl;
//    }
//    return coutt;
//}



//Review<std::string>* newReview = review->changeType(true); // Convertire la ReviewProduct
//Review* reviewPtr = new ReviewDrink<T>;
//ReviewDrink<T>* drinkReviewPtr = dynamic_cast<ReviewDrink<T>*>("", 0);
//        Review<T>* reviewPtr = new Review<T>("", 0); // Exemplu: trebuie să inițializezi cu parametrii relevanți
//        Review<T>* drinkReviewPtr = dynamic_cast<Review<T>*>(reviewPtr);


//        if (drinkReviewPtr) {
//            cout << "Felicitari!" << endl;
//        }

//void Review<T>::printReviews() {
//    std::cout << "Reviews for this product:" << std::endl;
//    for (const auto& pair : review) {
//        std::cout << "User: " << pair.first << ", Review: " << pair.second << std::endl;
//    }
//}


//                cout << "Thank you for taking your time to help us improve our products, " << name
//                     << "! You can either rate us using grades or your own words!" << endl;
//                cin >> review[name];
//                const ReviewApp<T> *appReview = dynamic_cast<const ReviewApp<T> *>(&review);
//
//                if (appReview) {
//                    appReview->makeReview(input, review, user);
//                }
//                else {
//                    cout << "We could not continue with your review. We are sorry. Try again later" << endl;
//                }

//template<typename T>
//std::map<std::string, T>& getReview() {
//    return review.second;
//}
