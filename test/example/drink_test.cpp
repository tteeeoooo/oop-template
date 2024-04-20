// #include <gtest/gtest.h>
// #include "drink.h"

// TEST(DrinkTest, Constructor) {
//     Drink drink("Coffee", 3.5);
//     EXPECT_EQ(drink.getDrinkName(), "Coffee");
//     EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 3.5);
// }

// TEST(DrinkTest, AssignmentOperator) {
//     Drink drink1("Tea", 2.0);
//     Drink drink2;
//     drink2 = drink1;
//     EXPECT_EQ(drink2.getDrinkName(), "Tea");
//     EXPECT_DOUBLE_EQ(drink2.getDrinkPrice(), 2.0);
// }

// TEST(DrinkTest, MenuOptions) {
//     Drink drink1("Coffee", 3.5);
//     Drink drink2("Tea", 2.0);
//     std::vector<Drink*> menu = {&drink1, &drink2};
//     testing::internal::CaptureStdout(); 
//     Drink::menuOptions(menu);
//     std::string output = testing::internal::GetCapturedStdout(); 
//     EXPECT_NE(output.find("Here are your options:"), std::string::npos);
//     EXPECT_NE(output.find("Product 1: Coffee - price with 19% TVA: 3.5"), std::string::npos);
//     EXPECT_NE(output.find("Product 2: Tea - price with 19% TVA: 2"), std::string::npos);
// }

// TEST(DrinkTest, PriceModifier) {
//     Drink drink("Water", 1.0);
//     EXPECT_DOUBLE_EQ(drink.priceModifier(), 1.0);
// }

// TEST(DrinkTest, GetDrinkName) {
//     Drink drink("Soda", 2.5);
//     EXPECT_EQ(drink.getDrinkName(), "Soda");
// }

// TEST(DrinkTest, GetDrinkPrice) {
//     Drink drink("Juice", 2.0);
//     EXPECT_DOUBLE_EQ(drink.getDrinkPrice(), 2.0);
// }
