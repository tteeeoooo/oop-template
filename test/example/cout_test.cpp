#include <gtest/gtest.h>
#include "cout.h"

TEST(CoutTest, MenuTextTest) {
    Cout::menuText();
    EXPECT_TRUE(true);
}

TEST(CoutTest, PriceCalculationTest) {
    EXPECT_FLOAT_EQ(Cout::priceCalculation(100.0, 0.0), 0.0);
    EXPECT_FLOAT_EQ(Cout::priceCalculation(100.0, 20.0), 20.0);
    EXPECT_FLOAT_EQ(Cout::priceCalculation(-50.0, 10.0), -5.0);
}

TEST(CoutTest, UnderLineTest) {
    Cout::underLine();
    EXPECT_TRUE(true);
}

TEST(CoutTest, UpperLineTest) {
    Cout::upperLine();
    EXPECT_TRUE(true);
}

TEST(CoutTest, TextToFinishTest) {
    int result = Cout::textToFinish();
    EXPECT_TRUE(result == 0);
}



TEST(CoutTest, CoutAbortedOrderTest) {
    Cout::coutAbortedOrder();
    EXPECT_TRUE(true);
}

TEST(CoutTest, CoutFinishedOrder) {
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    Cout::coutFinishedOrder();
    EXPECT_EQ(output.str(), "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)");

    std::cout.rdbuf(oldCout);
}

TEST(CoutTest, TodaysSalesTest) {
    Cout::todaysSales();
    EXPECT_TRUE(true);
}

TEST(CoutTest, ExitTextTest) {
    Cout::exitText();
    EXPECT_TRUE(true);
}
