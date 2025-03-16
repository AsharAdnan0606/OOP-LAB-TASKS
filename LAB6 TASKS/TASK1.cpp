#include <iostream>
#include <vector>
#include <string>

using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;
public:
    BankAccount(const string& accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
    }
    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    virtual void display() const {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(const string& accNum, double bal, double rate) : BankAccount(accNum, bal), interestRate(rate) {}
    void applyInterest() {
        balance += balance * interestRate;
    }
    void display() const override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit;
public:
    CheckingAccount(const string& accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}
    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }
    void display() const override {
        BankAccount::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

class BusinessAccount : public BankAccount {
    double taxRate;
public:
    BusinessAccount(const string& accNum, double bal, double tax) : BankAccount(accNum, bal), taxRate(tax) {}
    void deposit(double amount) override {
        balance += amount - (amount * taxRate);
    }
    void display() const override {
        BankAccount::display();
        cout << "Tax Rate: " << taxRate << endl;
    }
};

class Employee {
protected:
    string name;
public:
    Employee(const string& n) : name(n) {}
    virtual void roleInfo() const = 0;
    virtual ~Employee() {}
};

class Customer : public Employee {
public:
    Customer(const string& n) : Employee(n) {}
    void roleInfo() const override {
        cout << name << " is a Customer." << endl;
    }
};

class Teller : public Employee {
public:
    Teller(const string& n) : Employee(n) {}
    void freezeAccount(BankAccount& account) {
        cout << "Account frozen." << endl;
    }
    void roleInfo() const override {
        cout << name << " is a Teller." << endl;
    }
};

class Manager : public Teller {
public:
    Manager(const string& n) : Teller(n) {}
    void adjustLimits() {
        cout << "Manager adjusting account limits." << endl;
    }
    void roleInfo() const override {
        cout << name << " is a Manager." << endl;
    }
};

int main() {
    vector<BankAccount*> accounts;
    accounts.push_back(new SavingsAccount("SA123", 1000, 0.05));
    accounts.push_back(new CheckingAccount("CA123", 500, 200));
    accounts.push_back(new BusinessAccount("BA123", 10000, 0.02));

    for (auto acc : accounts) {
        acc->display();
        acc->deposit(500);
        acc->withdraw(300);
        acc->display();
        cout << "------" << endl;
    }

    Employee* emp1 = new Customer("Alice");
    Employee* emp2 = new Teller("Bob");
    Employee* emp3 = new Manager("Charlie");

    emp1->roleInfo();
    emp2->roleInfo();
    emp3->roleInfo();

    // Clean-up
    for (auto acc : accounts) {
        delete acc;
    }
    delete emp1;
    delete emp2;
    delete emp3;

    return 0;
}

