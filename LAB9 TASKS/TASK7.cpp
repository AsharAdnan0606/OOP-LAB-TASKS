#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int age;

public:
    // Virtual function to get data from the user
    virtual void getdata() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
    }

    // Virtual function to display data
    virtual void displaydata() {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }

    // Virtual function to calculate bonus
    virtual void bonus() = 0;  // Pure virtual function (abstract)
    
    // Virtual destructor
    virtual ~Person() {}
};

// Derived class Admin that inherits from Person
class Admin : public Person {
protected:
    double salary;

public:
    // Override the getdata method
    void getdata() override {
        Person::getdata();  // Get the data for name and age from base class
        cout << "Enter salary: ";
        cin >> salary;
    }

    // Override the displaydata method
    void displaydata() override {
        Person::displaydata();  // Display the name and age from base class
        cout << "Salary: " << salary << endl;
    }

    // Calculate bonus for Admin (10% of salary)
    void bonus() override {
        double admin_bonus = salary * 0.1;  // 10% of salary
        cout << "Admin Bonus: " << admin_bonus << endl;
    }
};

// Derived class Account that inherits from Person
class Account : public Person {
protected:
    double salary;

public:
    // Override the getdata method
    void getdata() override {
        Person::getdata();  // Get the data for name and age from base class
        cout << "Enter salary: ";
        cin >> salary;
    }

    // Override the displaydata method
    void displaydata() override {
        Person::displaydata();  // Display the name and age from base class
        cout << "Salary: " << salary << endl;
    }

    // Calculate bonus for Account (15% of salary)
    void bonus() override {
        double account_bonus = salary * 0.15;  // 15% of salary
        cout << "Account Bonus: " << account_bonus << endl;
    }
};

// Derived class Master that inherits from both Admin and Account
class Master : public Admin, public Account {
public:
    // Override the getdata method to combine the data for Admin and Account
    void getdata() override {
        Admin::getdata();  // Admin part
        Account::getdata();  // Account part
    }

    // Override the displaydata method to display both Admin and Account data
    void displaydata() override {
        Admin::displaydata();  // Admin part
        Account::displaydata();  // Account part
    }

    // Calculate bonus for Master (based on both Admin and Account salary)
    void bonus() override {
        // You can combine both bonuses here, for example
        Admin::bonus();
        Account::bonus();
    }
};

int main() {
    Person* employee;

    // Create an Admin employee and calculate bonus
    cout << "Enter details for Admin Employee:\n";
    employee = new Admin();
    employee->getdata();
    employee->displaydata();
    employee->bonus();

    // Create an Account employee and calculate bonus
    cout << "\nEnter details for Account Employee:\n";
    employee = new Account();
    employee->getdata();
    employee->displaydata();
    employee->bonus();

    // Create a Master employee and calculate bonus
    cout << "\nEnter details for Master Employee (Admin + Account):\n";
    employee = new Master();
    employee->getdata();
    employee->displaydata();
    employee->bonus();

    // Clean up memory
    delete employee;

    return 0;
}

