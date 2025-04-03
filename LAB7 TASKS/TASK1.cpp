#include <iostream>
#include <vector>
using namespace std;

class BankAccount {
protected:
    int accountNumber;
    string accountHolderName;
    double balance;
    string accType;
    vector<string> transactionHistory;

public:
    void setAccountInfo(int num, string name, double bal, string type) {
        accountNumber = num;
        accountHolderName = name;
        balance = bal;
        accType = type;
    }

    virtual void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposited: $" + to_string(amount));
    }

    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactionHistory.push_back("Withdrawn: $" + to_string(amount));
        } else {
            cout << "Insufficient Balance!\n";
        }
    }

    virtual void calculateInterest() = 0;

    virtual void printStatement() {
        cout << "Transaction History for " << accountHolderName << ":\n";
        for (const string &entry : transactionHistory) {
            cout << entry << endl;
        }
    }

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Account Type: " << accType << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double interestRate = 0.04;
    double minimumBalance = 500;

public:
    void calculateInterest() override {
        if (balance >= minimumBalance) {
            double interest = balance * interestRate;
            balance += interest;
            transactionHistory.push_back("Interest Added: $" + to_string(interest));
        }
    }
};

class CheckingAccount : public BankAccount {
private:
    double overdraftLimit = 1000;

public:
    void withdraw(double amount) override {
        if (amount <= balance + overdraftLimit) {
            balance -= amount;
            transactionHistory.push_back("Withdrawn (Overdraft Allowed): $" + to_string(amount));
        } else {
            cout << "Overdraft Limit Exceeded!\n";
        }
    }

    void calculateInterest() override {
        transactionHistory.push_back("No interest for Checking Accounts.");
    }
};

class FixedDepositAccount : public BankAccount {
private:
    double fixedInterestRate = 0.08;
    int maturityPeriod = 12;

public:
    void calculateInterest() override {
        double interest = balance * fixedInterestRate;
        balance += interest;
        transactionHistory.push_back("Fixed Deposit Interest Added: $" + to_string(interest));
    }
};

int main() {
    SavingsAccount savings;
    CheckingAccount checking;
    FixedDepositAccount fixedDeposit;

    savings.setAccountInfo(101, "Alice", 1000, "Savings");
    checking.setAccountInfo(102, "Bob", 500, "Checking");
    fixedDeposit.setAccountInfo(103, "Charlie", 5000, "Fixed Deposit");

    savings.deposit(500);
    savings.withdraw(200);
    savings.calculateInterest();
    savings.printStatement();
    cout << "---------------------------------\n";

    checking.deposit(300);
    checking.withdraw(800);
    checking.withdraw(1000);
    checking.printStatement();
    cout << "---------------------------------\n";

    fixedDeposit.calculateInterest();
    fixedDeposit.printStatement();

    return 0;
}

