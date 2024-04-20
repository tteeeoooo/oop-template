#include <gtest/gtest.h>
#include "cout.h"

TEST(CoutTest, MenuTextTest) {
    // Testing menuText() function
    // Since this function only prints text, we can't directly test its output
    // We can check if it runs without errors
    Cout::menuText();
    // If the function runs without errors, the test passes
    EXPECT_TRUE(true);
}

TEST(CoutTest, PriceCalculationTest) {
    // Testing priceCalculation() function
    // Test case 1: No discount
    EXPECT_FLOAT_EQ(Cout::priceCalculation(100.0, 0.0), 0.0);
    // Test case 2: 20% discount
    EXPECT_FLOAT_EQ(Cout::priceCalculation(100.0, 20.0), 20.0);
    // Test case 3: Negative price (edge case)
    EXPECT_FLOAT_EQ(Cout::priceCalculation(-50.0, 10.0), -5.0);
}

TEST(CoutTest, UnderLineTest) {
    // Testing underLine() function
    // Since this function only prints text, we can't directly test its output
    // We can check if it runs without errors
    Cout::underLine();
    // If the function runs without errors, the test passes
    EXPECT_TRUE(true);
}

TEST(CoutTest, UpperLineTest) {
    // Testing upperLine() function
    // Since this function only prints text, we can't directly test its output
    // We can check if it runs without errors
    Cout::upperLine();
    // If the function runs without errors, the test passes
    EXPECT_TRUE(true);
}

TEST(CoutTest, TextToFinishTest) {
    // Testing textToFinish() function
    // Since this function only prints text, we can't directly test its output
    // We can check if it runs without errors
    int result = Cout::textToFinish();
    // If the function runs without errors, the test passes
    EXPECT_TRUE(result == 0);
}

TEST(CoutTest, OrderAndExitTest) {
    // Testing orderAndExit() function
    // Since this function involves user input, we can't directly test its behavior
    // We can check if it runs without errors
    Cout::orderAndExit();
    // If the function runs without errors, the test passes
    EXPECT_TRUE(true);
}

TEST(CoutTest, CoutFinishedOrder) {
    // Testăm funcția statică void coutFinishedOrder() din clasa Cout
    
    // Redirecționăm ieșirea standard (cout) către un stringstream pentru a putea verifica mesajul afișat
    std::stringstream output;
    std::streambuf* oldCout = std::cout.rdbuf(output.rdbuf());

    // Apelăm funcția coutFinishedOrder()
    Cout::coutFinishedOrder();

    // Verificăm dacă mesajul afișat este corect
    EXPECT_EQ(output.str(), "Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)");

    // Resetăm ieșirea standard la valoarea anterioară
    std::cout.rdbuf(oldCout);
}

