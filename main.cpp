// Experiment 9: Custom exception hierarchy for a banking transaction
#include <iostream>
#include <exception>
#include <string>
using namespace std;

class BankingException : public exception {
public:
    const char* what() const noexcept override {
        return "A banking error occurred.";
    }
};

class InvalidAmountException : public BankingException {
public:
    const char* what() const noexcept override {
        return "Transaction amount must be greater than zero.";
    }
};

class InsufficientFundsException : public BankingException {
public:
    const char* what() const noexcept override {
        return "Transaction failed: insufficient account balance.";
    }
};

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double openingBalance) : balance(openingBalance) {}

    void deposit(double amount) {
        if (amount <= 0) throw InvalidAmountException();
        balance += amount;
        cout << "Deposit successful.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) throw InvalidAmountException();
        if (amount > balance) throw InsufficientFundsException();
        balance -= amount;
        cout << "Withdrawal successful.\n";
    }

    double getBalance() const {
        return balance;
    }
};

int main() {
    BankAccount account(5000.0);

    try {
        account.deposit(1000.0);
        account.withdraw(2000.0);
        account.withdraw(10000.0); // Demonstrates insufficient-funds exception
    }
    catch (const InvalidAmountException& error) {
        cerr << "Invalid amount: " << error.what() << '\n';
    }
    catch (const InsufficientFundsException& error) {
        cerr << "Insufficient funds: " << error.what() << '\n';
    }
    catch (const BankingException& error) {
        cerr << "Banking exception: " << error.what() << '\n';
    }

    cout << "Final balance: " << account.getBalance() << '\n';
    return 0;
}
