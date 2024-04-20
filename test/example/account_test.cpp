#include <gtest/gtest.h>
#include "account.h" 

TEST(AccountTest, InputVisual) {
    Account account; 

    // Testăm fiecare caz posibil al switch-ului în funcția inputVisual
    EXPECT_EQ(account.inputVisual(1), "Premium plus");
    EXPECT_EQ(account.inputVisual(2), "Premium");
    EXPECT_EQ(account.inputVisual(3), "Business casual");
    EXPECT_EQ(account.inputVisual(0), "abort mission");
}

