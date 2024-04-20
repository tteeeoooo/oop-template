
// #include <gtest/gtest.h>
// #include "cout.h"

// TEST(CoutTest, PriceCalculation) {
//     EXPECT_FLOAT_EQ(Cout::priceCalculation(100, 25), 25);
// }

// TEST(CoutTest, OrderAndExit) {
//     std::istringstream input("1");
//     std::cin.rdbuf(input.rdbuf()); 
//     testing::internal::CaptureStdout(); 
//     Cout::orderAndExit();
//     std::string output = testing::internal::GetCapturedStdout(); 
//     EXPECT_EQ(output, "\nWould you like to order your cart?\nPress 1 to confirm!\nPress 0 to exit! :(\n");

//     std::istringstream input2("0");
//     std::cin.rdbuf(input2.rdbuf()); 
//     testing::internal::CaptureStdout(); 
//     Cout::orderAndExit();
//     output = testing::internal::GetCapturedStdout();
//     EXPECT_EQ(output, "\nWould you like to order your cart?\nPress 1 to confirm!\nPress 0 to exit! :(\n");
// }

// TEST(CoutTest, MenuText) {
//     testing::internal::CaptureStdout(); 
//     Cout::menuText();
//     std::string output = testing::internal::GetCapturedStdout(); 
//     EXPECT_NE(output.find("Choose the index of a product each time your want to add it to your cart! :D"), std::string::npos);
//     EXPECT_NE(output.find("If you want to delete a product from your cart, press '20'."), std::string::npos);
//     EXPECT_NE(output.find("When you are done making your cart, just press 0! :)"), std::string::npos);
// }

// TEST(CoutTest, TextToFinish) {
//     testing::internal::CaptureStdout(); 
//     Cout::textToFinish();
//     std::string output = testing::internal::GetCapturedStdout(); 
//     EXPECT_NE(output.find("Are you sure you don't want to edit your cart?"), std::string::npos);
//     EXPECT_NE(output.find("Press 1 to go introduce your delivery information!"), std::string::npos);
//     EXPECT_NE(output.find("Press 2 to go back to editing your cart!"), std::string::npos);
//     EXPECT_NE(output.find("Press 0 to exit :("), std::string::npos);
// }

// TEST(CoutTest, CoutFinishedOrder) {
//     testing::internal::CaptureStdout(); 
//     Cout::coutFinishedOrder();
//     std::string output = testing::internal::GetCapturedStdout(); 
//     EXPECT_NE(output.find("Thank you for your order! We are grinding your coffee right now, to make sure that you will have it as soon as possible! :)"), std::string::npos);
// }

// TEST(CoutTest, CoutAbortedOrder) {
//     testing::internal::CaptureStdout(); 
//     Cout::coutAbortedOrder();
//     std::string output = testing::internal::GetCapturedStdout(); 
//     EXPECT_NE(output.find("We are sorry that you are leaving! See you next time!"), std::string::npos);
// }

// TEST(CoutTest, TodaysSales) {
//     testing::internal::CaptureStdout(); 
//     Cout::todaysSales();
//     std::string output = testing::internal::GetCapturedStdout(); 
//     EXPECT_NE(output.find("Here is today's deal!"), std::string::npos);
//     EXPECT_NE(output.find("25% off for orders over $30"), std::string::npos);
// }
