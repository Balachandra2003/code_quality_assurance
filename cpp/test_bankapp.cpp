#include "gtest/gtest.h"
#include "bankapp.cpp"  // Include your bank.cpp directly

TEST(BankAccountTest, DepositAndWithdraw) {
    BankAccount acc("TestUser", 1000);
    acc.deposit(500);
    EXPECT_EQ(acc.getBalance(), 1500);
    acc.withdraw(200);
    EXPECT_EQ(acc.getBalance(), 1300);
}

TEST(BankAccountTest, WithdrawInsufficient) {
    BankAccount acc("TestUser", 100); 
    acc.withdraw(200);
    EXPECT_EQ(acc.getBalance(), 100);  // Balance should remain the same
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
