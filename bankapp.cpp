#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive!" << endl;
            return;
        }
        balance += amount;
        cout << "Deposited: $" << amount << " -> balance: $" << balance << endl;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawn: $" << amount << " -> Remaining balance: $" << balance << endl;
        }
    }

    void displayBalance() {
        cout << "Account Holder: " << accountHolder
             << ", Balance: $" << balance << endl;
    }
};

int main() {
    string name;
    cout<<"Enter Your Name: ";
    cin>>name;
    BankAccount myAccount(name, 1000);
    int choice;  

    while (choice != 4) {
        cout << "\nMenu:\n";
        cout << "1 - Balance Enquiry\n";
        cout << "2 - Deposit Amount\n";
        cout << "3 - Withdraw Amount\n";
        cout << "4 - Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myAccount.displayBalance();
                break;
            case 2: {
                cout << "Enter amount to deposit: ";
                double depositamount;
                cin >> depositamount;
                myAccount.deposit(depositamount);
                break;
            }
            case 3: {
                cout << "Enter amount to withdraw: ";
                double withdrawamount;
                cin >> withdrawamount;
                myAccount.withdraw(withdrawamount);
                break;
            }
            case 4:
                cout << "Thank you \n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
