#include <gtest/gtest.h>
#include "cout.h"

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
