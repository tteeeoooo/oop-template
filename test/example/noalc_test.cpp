#include <gtest/gtest.h>
#include "noalc.h"

TEST(SuiteName, TestName) {
    // Aici adaugăm codul pentru testarea operatorului <<
    NoAlc drink("Soda", 2.5, 100);
    std::ostringstream oss;
    oss << drink;
    EXPECT_EQ(oss.str(), "Soda 2.5 100");
}
