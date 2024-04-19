#include "account.h" 
#include <gtest/gtest.h> 
TEST(AccountTest, ConstructorTest) {
    Account acc("JohnDoe", "password123");
    EXPECT_EQ(acc.getName(), "JohnDoe");
}

TEST(AccountTest, CopyConstructorTest) {
    Account original("JaneDoe", "qwerty");
    Account copy(original);
    EXPECT_EQ(copy.getName(), "JaneDoe");
}

TEST(AccountTest, GetNameTest) {
    Account acc("Alice", "secret");
    EXPECT_EQ(acc.getName(), "Alice");
}

TEST(AccountTest, ExcTest) {
    Account acc;
    std::stringstream input("1\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf()); 
    EXPECT_EQ(acc.exc(), 1);
    std::cin.rdbuf(old_cin); 
}

TEST(AccountTest, UserReadTest) {
    Account acc;
    std::stringstream input("JohnDoe\n1\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());
    acc.userRead();
    std::cin.rdbuf(old_cin);
}

TEST(AccountTest, PremiumTextTest) {
    Account acc;
    std::stringstream ss;
    acc.premiumText();
    std::string output = ss.str();
    EXPECT_NE(output.find("Discover the advantages of premium!"), std::string::npos);
}

TEST(AccountTest, InputDataTest) {
    Account acc;
    std::stringstream input("1234567890123456 JohnDoe 123\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());
    acc.inputData();
    std::cin.rdbuf(old_cin);
}

TEST(AccountTest, InputVisualTest) {
    Account acc;
    EXPECT_EQ(acc.inputVisual(1), "Premium plus");
}

TEST(AccountTest, UpgradeTest) {
    Account acc;
    std::stringstream input("1\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());
    acc.upgrade();
    std::cin.rdbuf(old_cin);
}

TEST(AccountTest, SaveTest) {
    Account acc("Alice", "pass123");
    acc.save();
    Verificăm dacă fișierul date.txt conține datele corecte
}

TEST(AccountTest, AssignmentOperatorTest) {
    Account original("Bob", "pass123");
    Account copy;
    copy = original;
    EXPECT_EQ(copy.getName(), "Bob");
}

TEST(AccountTest, OutputOperatorTest) {
    Account acc("Eve", "mysecret");
    std::stringstream ss;
    ss << acc;
    std::string output = ss.str();
    EXPECT_NE(output.find("Eve"), std::string::npos);
}

TEST(AccountTest, InputOperatorTest) {
    Account acc;
    std::stringstream ss("John Jane\npass123\n");
    ss >> acc;
    EXPECT_EQ(acc.getName(), "John");
}
