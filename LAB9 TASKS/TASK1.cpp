#include <iostream>
#include <string>
#include <limits>

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawalLimit;
    double dailyDepositAmount;
    double dailyWithdrawalAmount;

public:
    Wallet() {
        balance = 0.0;
        dailyDepositLimit = 1000.0; // example daily limit for deposit
        dailyWithdrawalLimit = 500.0; // example daily limit for withdrawal
        dailyDepositAmount = 0.0;
        dailyWithdrawalAmount = 0.0;
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            std::cout << "Deposit amount must be positive!" << std::endl;
            return false;
        }
        if (dailyDepositAmount + amount > dailyDepositLimit) {
            std::cout << "Exceeded daily deposit limit!" << std::endl;
            return false;
        }

        balance += amount;
        dailyDepositAmount += amount;
        std::cout << "Deposited: " << amount << ", New Balance: " << balance << std::endl;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cout << "Withdrawal amount must be positive!" << std::endl;
            return false;
        }
        if (balance < amount) {
            std::cout << "Insufficient balance!" << std::endl;
            return false;
        }
        if (dailyWithdrawalAmount + amount > dailyWithdrawalLimit) {
            std::cout << "Exceeded daily withdrawal limit!" << std::endl;
            return false;
        }

        balance -= amount;
        dailyWithdrawalAmount += amount;
        std::cout << "Withdrew: " << amount << ", New Balance: " << balance << std::endl;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

class User {
private:
    std::string userID;
    std::string name;
    Wallet wallet;

public:
    User(std::string id, std::string userName) {
        userID = id;
        name = userName;
    }

    bool deposit(double amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(double amount) {
        return wallet.withdraw(amount);
    }

    double checkBalance() const {
        return wallet.getBalance();
    }
};

int main() {
    User user1("001", "John Doe");
    User user2("002", "Jane Smith");

    user1.deposit(200);
    user1.withdraw(50);
    user1.deposit(1200); // Should fail due to limit

    user2.deposit(300);
    user2.withdraw(400); // Should fail due to insufficient balance

    std::cout << "User 1 balance: " << user1.checkBalance() << std::endl;
    std::cout << "User 2 balance: " << user2.checkBalance() << std::endl;

    return 0;
}

