#include <iostream>
using namespace std;

class Person {
protected:
    int employeeID;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }
    void displayData() const {
        cout << "Employee ID: " << employeeID << "\n";
    }
};

class Admin : public Person {
protected:
    string name;
    double monthlyIncome;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }
    double bonus() const {
        return monthlyIncome * 0.05 * 12;
    }
    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << "\n";
        cout << "Monthly Income: " << monthlyIncome << "\n";
        cout << "Annual Bonus: " << bonus() << "\n";
    }
};

class Accounts : public Admin {
public:
    void getData() {
        Admin::getData();
    }
    void displayData() const {
        Admin::displayData();
    }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;

    cout << "Enter details for Admin Employee:\n";
    adminEmp.getData();
    cout << "\nEnter details for Accounts Employee:\n";
    accountsEmp.getData();

    cout << "\nAdmin Employee Details:\n";
    adminEmp.displayData();
    cout << "\nAccounts Employee Details:\n";
    accountsEmp.displayData();
    
    return 0;
}

