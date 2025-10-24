// Copyright 2025 Balu
#include <gtest/gtest.h>
#include "bankapp.h"

TEST(BankAccountTest, DepositIncreasesBalance) {
    BankAccount acc("Balu", 1000);
    acc.deposit(500);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 1500);
}

TEST(BankAccountTest, WithdrawDecreasesBalance) {
    BankAccount acc("Balu", 1000);
    acc.withdraw(400);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 600);
}

TEST(BankAccountTest, WithdrawTooMuchDoesNothing) {
    BankAccount acc("Balu", 500);
    acc.withdraw(1000);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 500);
}

TEST(BankAccountTest, DepositNegativeDoesNothing) {
    BankAccount acc("Balu", 1000);
    acc.deposit(-200);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 1000);
}
