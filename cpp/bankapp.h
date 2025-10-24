// Copyright 2025 Balu
#ifndef BANK_APP_H_
#define BANK_APP_H_

#include <iostream>
#include <string>

class BankAccount {
 public:
    BankAccount(const std::string& name, double initialBalance);

    void deposit(double amount);
    void withdraw(double amount);
    double getBalance() const;
    std::string getAccountHolder() const;
    void displayBalance() const;

 private:
    std::string accountHolder;
    double balance;
};

#endif  // BANK_APP_H_
