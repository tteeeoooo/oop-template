#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <cmath>
//#include "reviewDrink.h"
//#include "reviewapp.h"
#include "appreview.h"
#include "drinkreview.h"

//using namespace std;

class Account;

class Drink;

class Cart;

template <typename T>
class Review {
protected:
    std::map<std::string, T> review;    

public:
    T& operator[](const std::string& key) {
        return review[key];
    }


    explicit Review(const std::map<std::string, T>& rev) : review(rev) {}

    explicit Review(const string& cheie = "General", const T& valoare = T{}) {
        review[cheie] = valoare;
    }

    std::map<std::string, T> getReview() const {
        return review;
    }

    const std::map<std::string, T>& getReview();

    void addReview(const std::string& user, const T& reviewText) {
        review[user] = reviewText;
    }

    void printReviews(){
        std::ifstream f("fisier1.txt");
        if (!f.is_open()) {
            std::cerr << "Unable to open file fisier.txt" << std::endl;
            return;
        }
        cout << "Reviews for this product:" << std::endl;
        string user, reviewText;

        Review<string> opinion;
        while (f >> user >> reviewText) {
            opinion.addReview(user, reviewText);
        }
        f.close();


        std::vector<std::pair<std::string, T>> reviewVector(review.begin(), review.end());

        std::sort(reviewVector.begin(), reviewVector.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });



        for (const auto& parere : review) {
            cout << parere.first << endl << parere.second;
            cout << endl << endl;
        }
    }

    static void makeReview(Review<T> parere, const vector<Drink*>& menu){
        cout << "Would you like to give a review to our app or one of our products?" << endl;
        cout << "Press 1 for app" << endl;
        cout << "Press 2 for product" << endl;
        try {
            short int input;

            cin >> input;
            if (input == 1) {
                Review<T>* reviewPtr1 = new ReviewApp<T>(parere);
                ReviewApp<T>* reviewAppPtr = dynamic_cast<ReviewApp<T>*>(reviewPtr1); 

                if (reviewAppPtr) {
                    reviewAppPtr -> makeReviewApp();
                    delete reviewPtr1;
                }
                else {
                    cout << "nu merge downcasting-ul pentru ReviewApp" << endl;
                    delete reviewPtr1;
                }


            }

            else {
                if (input == 2) {
                    Review<T>* reviewPtr2 = new ReviewProduct<T>(parere);
                    ReviewProduct<T>* reviewProductPtr = dynamic_cast<ReviewProduct<T>*>(reviewPtr2); 

                    if (reviewProductPtr) {
                        reviewProductPtr -> makeReviewProduct(menu);
                        delete reviewPtr2;
                    }
                    else {
                        cout << "nu merge downcasting-ul pentru ReviewProduct" << endl;
                        delete reviewPtr2;
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

    void checkGrade(float &grade) {
        if (float(grade) < 0) {
            grade = 0;
        }
        else {
            if (float(grade) > 5) {
                grade = 5;      //daca se introduce o nota care nu e intre 0 si 5 devine cea mai apropiata de limita
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

    bool checkWords(const string &note) {
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

    void sortLambda(Review<T>& reviewSituation) {
        if constexpr (std::is_same_v<T, float>) {
            std::vector<std::pair<std::string, T>> reviewsVector(reviewSituation.reviews.begin(), reviewSituation.reviews.end());

            std::sort(reviewsVector.begin(), reviewsVector.end(),
                      [](const std::pair<std::string, T>& review1, const std::pair<std::string, T>& review2) {
                          return review1.second < review2.second;
                      });

            reviewSituation.reviews.clear();
            for (const auto& parere : reviewsVector) {
                reviewSituation.reviews.insert(parere);
            }
        }
    }

    virtual ~Review() = default;
};





