#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Employee {
protected:
    int id;
    string name;

public:
    Employee(int id, const string& name) : id(id), name(name) {}
    virtual void showInfo() const {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill() = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int id, const string& name) : Employee(id, name) {}

    void takeOrder() override {
        cout << name << " is taking the order." << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int id, const string& name) : Employee(id, name) {}

    void prepareOrder() override {
        cout << name << " is preparing the order." << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int id, const string& name) : Employee(id, name) {}

    void generateBill() override {
        cout << name << " is generating the bill." << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int id, const string& name) : Employee(id, name) {}

    void takeOrder() override {
        cout << name << " (Manager) is taking the order." << endl;
    }

    void generateBill() override {
        cout << name << " (Manager) is generating the bill." << endl;
    }
};

class Menu {
public:
    virtual double calculateTotal(double basePrice) const = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    double calculateTotal(double basePrice) const override {
        return basePrice; // No additional tax
    }
};

class BeverageMenu : public Menu {
public:
    double calculateTotal(double basePrice) const override {
        return basePrice * 1.1; // 10% beverage tax
    }
};

int main() {
    vector<Employee*> employees;
    
    Waiter w(1, "Alice");
    Chef c(2, "Bob");
    Cashier ca(3, "Charlie");
    Manager m(4, "Diana");

    employees.push_back(&w);
    employees.push_back(&c);
    employees.push_back(&ca);
    employees.push_back(&m);

    for (auto emp : employees) {
        emp->showInfo();
    }

    cout << endl;

    IOrderTaker* orderTaker = &w;
    orderTaker->takeOrder();

    IOrderPreparer* orderPreparer = &c;
    orderPreparer->prepareOrder();

    IBiller* biller = &ca;
    biller->generateBill();

    Manager manager(5, "Eve");
    manager.takeOrder();
    manager.generateBill();

    cout << endl;

    FoodMenu foodMenu;
    BeverageMenu beverageMenu;
    cout << "Food Total: " << foodMenu.calculateTotal(100) << endl;
    cout << "Beverage Total: " << beverageMenu.calculateTotal(100) << endl;

    return 0;
}

