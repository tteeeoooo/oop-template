#include <gtest/gtest.h>
#include "account.h"

TEST(AccountTest, DefaultConstructor) {
    Account acc;
    EXPECT_EQ(acc.getName(), ""); 
}

TEST(AccountTest, ParameterizedConstructor) {
    Account acc("username", "password");
    EXPECT_EQ(acc.getName(), "username"); 
}

TEST(AccountTest, UpgradeTest) {
    Account acc("username", "password");
    acc.upgrade();
}

TEST(AccountTest, UserReadTest) {
    Account acc("username", "password");
    acc.userRead();
}

TEST(AccountTest, OutputOperatorTest) {
    Account acc("username", "password");
    std::ostringstream oss;
    oss << acc; 
    std::string output = oss.str();
    EXPECT_TRUE(output.find("username") != std::string::npos); 
}

TEST(AccountTest, InputOperatorTest) {
    Account acc;
    std::istringstream iss("newusername\nnewpassword\n");
    iss >> acc; 
    EXPECT_EQ(acc.getName(), "newusername"); 
}

TEST(AccountTest, SaveTest) {
    Account acc("username", "password");
    acc.save(); 
}
