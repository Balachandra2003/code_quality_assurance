// copyright 2025 Balu
#include <iostream>
#include <string>

class BankAccount {
 public:
    BankAccount(const std::string& name, double initialBalance)
        : accountHolder(name), balance(initialBalance) {
    }

    void deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive!" << std::endl;
            return;
        }
        balance += amount;
        std::cout << "Deposited: $" << amount
                  << " -> balance: $" << balance << std::endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive!" << std::endl;
            return;
        }
        if (amount > balance) {
            std::cout << "Insufficient funds!" << std::endl;
        } else {
            balance -= amount;
            std::cout << "Withdrawn: $" << amount
                      << " -> Remaining balance: $" << balance << std::endl;
        }
    }

    void displayBalance() {
        std::cout << "Account Holder: " << accountHolder
                  << ", Balance: $" << balance << std::endl;
    }

 private:
    std::string accountHolder;
    double balance;
};

int main() {
    std::string name;
    std::cout << "Enter Your Name: ";
    std::cin >> name;

    BankAccount myAccount(name, 1000);
    int choice = 0;
    while (choice != 4) {
        std::cout << "\nMenu:\n";
        std::cout << "1 - Balance Enquiry\n";
        std::cout << "2 - Deposit Amount\n";
        std::cout << "3 - Withdraw Amount\n";
        std::cout << "4 - Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                myAccount.displayBalance();
                break;
            case 2: {
                std::cout << "Enter amount to deposit: ";
                double depositAmount;
                std::cin >> depositAmount;
                myAccount.deposit(depositAmount);
                break;
            }
            case 3: {
                std::cout << "Enter amount to withdraw: ";
                double withdrawAmount;
                std::cin >> withdrawAmount;
                myAccount.withdraw(withdrawAmount);
                break;
            }
            case 4:
                std::cout << "Thank you\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
