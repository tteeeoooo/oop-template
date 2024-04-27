#include <iostream>
#include <string>
#include <map>
#include <unordered_set>

using namespace std;

template <typename T>
class Review {
protected:
    std::map<std::string, T> review;

public:
    Review();

    Review(const std::map<std::string, T>& firstReview) : review(firstReview) {}

    void addReview(const std::string& Name, const T &note);

    void printReviews();

    void coutReview();

    void checkGrade(const T &grade);

    bool checkWords(std::string &note);

    void sortLambda(Review<T>& reviewSituation);

    ~Review() = default;
};

#ifndef OOP_TEMPLATEBASE_H
#define OOP_TEMPLATEBASE_H

#endif //OOP_TEMPLATEBASE_H
