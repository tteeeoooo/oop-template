#include <gtest/gtest.h>
#include "cart.h" 

TEST(CartTest, OrderCheckout) {
    Cart cart;
    std::vector<Drink*> coffeeMenu; // Presupunând că aceasta este o listă validă de băuturi

    // Simulăm un input care duce la checkout direct
    std::stringstream input_stream("0\n");
    std::cin.rdbuf(input_stream.rdbuf());

    // Apelăm funcția order() și verificăm dacă returnează prețul corect (0 pentru un coș gol)
    EXPECT_EQ(cart.order(cart, coffeeMenu), 0);
}

// TEST(CartTest, Order) {
//     std::vector<Drink*> coffeeMenu;
//     coffeeMenu.push_back(new MockDrink("Coffee1", 5.0));
//     coffeeMenu.push_back(new MockDrink("Coffee2", 3.0));
//     Cart cart;
//     std::stringstream user_input;
//     user_input << "1\n0\n"; 
//     std::cin.rdbuf(user_input.rdbuf());

//     float totalPrice = cart.order(cart, coffeeMenu);
//     EXPECT_EQ(totalPrice, 5.0); 
// }

// TEST(CartTest, CartPrice) {
//     float expected_price = 50.0;
//     Cart cart(expected_price);
//     EXPECT_EQ(cart.cartPrice(), expected_price);
// }

// #include <gtest/gtest.h>
// #include <iostream>
// #include <vector>
// #include <sstream> 
// #include "cart.h"

// TEST(CartTest, ConstructorTest) {
//     // Creează un obiect de tip Cart
//     Cart cart;

//     EXPECT_EQ(cart.cartPrice(), 0.0f);
//     EXPECT_TRUE(cart.getDrinks(cart).empty());
// }

// TEST(CartTest, ProductDeleteTest) {
//     Cart cart;
//     std::vector<Drink*> drinks;
//     drinks.push_back(new Drink("Coffee", 3.5f)); 
//     drinks.push_back(new Drink("Tea", 2.0f)); 
//     cart = Cart(drinks, 5.5f, {3.5f, 2.0f}); 
    
//     cart.productDelete(0);

//     EXPECT_EQ(cart.cartPrice(), 2.0f);
//     EXPECT_EQ(cart.getDrinks(cart).size(), 1);

//     for (auto drink : drinks) {
//         delete drink;
//     }
// }

// TEST(CartTest, CartPriceTest) {
//     Cart cart;
//     std::vector<Drink*> drinks;
//     drinks.push_back(new Drink("Coffee", 3.5f)); 
//     drinks.push_back(new Drink("Tea", 2.0f)); 
//     cart = Cart(drinks, 5.5f, {3.5f, 2.0f}); 
    
//     EXPECT_EQ(cart.cartPrice(), 5.5f);
    
//     for (auto drink : drinks) {
//         delete drink;
//     }
// }

// TEST(CartTest, AssignmentOperatorTest) {
//     Cart cart1, cart2;
//     std::vector<Drink*> drinks;
//     drinks.push_back(new Drink("Coffee", 3.5f)); // Adaugă o băutură în coș
//     drinks.push_back(new Drink("Tea", 2.0f)); // Adaugă încă o băutură în coș
//     cart1 = Cart(drinks, 5.5f, {3.5f, 2.0f}); // Actualizează coșul cu băuturile adăugate

//     cart2 = cart1;

//     EXPECT_EQ(cart1.cartPrice(), cart2.cartPrice());
//     EXPECT_EQ(cart1.getDrinks(cart1).size(), cart2.getDrinks(cart2).size());
    
//     for (auto drink : drinks) {
//         delete drink;
//     }
// }

// TEST(CartTest, OutputOperatorTest) {
//     Cart cart;
//     std::vector<Drink*> drinks;
//     drinks.push_back(new Drink("Coffee", 3.5f)); 
//     cart = Cart(drinks, 3.5f, {3.5f}); 

//     std::stringstream output_stream;
//     std::streambuf *old_cout = std::cout.rdbuf(output_stream.rdbuf());

//     std::cout << cart;

//     std::cout.rdbuf(old_cout);

//     std::string expected_output = "Your shopping cart status:\nProduct 1: Coffee  \n3.5\n";
//     EXPECT_EQ(output_stream.str(), expected_output);
    
//     for (auto drink : drinks) {
//         delete drink;
//     }
// }

// TEST(CartTest, EverythingFunction) {
//     Cart cart;
//     vector<Drink*> coffeeMenu; // O listă goală de produse
//     EXPECT_NO_THROW({
//         cart.everything(cart, coffeeMenu);
//     });
// }

// TEST(CartTest, GiveATipFunction) {
//     Cart cart;
//     EXPECT_NO_THROW({
//         cart.giveATip(cart);
//     });
// }

