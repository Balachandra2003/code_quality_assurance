"""Simple interactive bank account application using OOP in Python."""


class BankAccount:
    """A class representing a simple bank account."""

    def __init__(self, name, initial_balance=1000):
        """Initialize the account with holder's name and initial balance."""
        self.account_holder = name
        self.balance = initial_balance

    def deposit(self, amount):
        """Deposit a positive amount to the account."""
        if amount <= 0:
            print("Deposit amount must be positive!")
            return
        self.balance += amount
        print(f"Deposited: ${amount} -> balance: ${self.balance}")

    def withdraw(self, amount):
        """Withdraw a valid amount if sufficient funds are available."""
        if amount <= 0:
            print("Withdrawal amount must be positive!")
            return
        if amount > self.balance:
            print("Insufficient funds!")
        else:
            self.balance -= amount
            print(f"Withdrawn: ${amount}->Remaining balance: ${self.balance}")

    def display_balance(self):
        """Display the account holder's name and current balance."""
        print(f"Account Holder:{self.account_holder},Balance:${self.balance}")


def main():
    """Main function to interact with the user via CLI."""
    name = input("Enter your name: ")
    account = BankAccount(name)

    while True:
        print("\nMenu:")
        print("1 - Balance Enquiry")
        print("2 - Deposit Amount")
        print("3 - Withdraw Amount")
        print("4 - Exit")

        choice = input("Enter your choice: ")

        if choice == "1":
            account.display_balance()
        elif choice == "2":
            try:
                amount = float(input("Enter amount to deposit: "))
                account.deposit(amount)
            except ValueError:
                print("Please enter a valid number.")
        elif choice == "3":
            try:
                amount = float(input("Enter amount to withdraw: "))
                account.withdraw(amount)
            except ValueError:
                print("Please enter a valid number.")
        elif choice == "4":
            print("Thank you!")
            break
        else:
            print("Invalid choice! Please try again.")


if __name__ == "__main__":
    main()
