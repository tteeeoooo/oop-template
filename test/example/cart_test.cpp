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

