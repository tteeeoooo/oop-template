#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <math.h>
#include <unordered_set>
#include "templateBase.h"
using namespace std;

//template class Review<std::string>;
//template class Review<float>;

template<typename T>
void Review<T>::addReview(const std::string& Name, const T &note) {
    review[Name] = note;
}

template<typename T>
void Review<T>::printReviews() {
    std::cout << "Reviews for this product:" << std::endl;
    for (const auto& pair : review) {
        std::cout << "User: " << pair.first << ", Review: " << pair.second << std::endl;
    }
}

template<typename T>
void Review<T>::coutReview() {
    short int input;
    string note;
    cout << "Name: ";
    cin >> review.first;
    cout << "Do you want to give us a grade or a more detailed review?" << endl;
    cout << "Press 1 for grade";
    cout << "Press 2 for detailed review";
    cin >> input;
    if (input == 1) {
        cout << "Grade: ";
        cin >> review.second;
        cout << "/5" << endl;
        checkGrade(review.second);
    }
    else {
        while (true) {
            try {
                cout << "Note: ";
                cin << review.second;
                if (checkWords(review.second) == false) {
                    cout << endl << "Thank you for your review!" << endl;
                }
                else {
                    throw std::invalid_argument("Your choice is invalid. Please try again!");
                }
            }
            catch (const std::exception& e) {
                std::cerr << "Error: " << e.what() << std::endl;
                cin.clear();
            }
        }
    }
    addReview(review.first, review.second);
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
                grade = floor(grade);
            }
            else {
                grade = ceil(grade);
            }
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
            cout << "We are sorry, but your review is in violation of our policy.";
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
