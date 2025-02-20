#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class MenuItem {
public:
    string name, type;
    double price;
    MenuItem(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
private:
    string name;
    vector<MenuItem> menu;
    vector<string> orders;
public:
    CoffeeShop(string n, vector<MenuItem> m) : name(n), menu(m) {}

    string addOrder(string item) {
        for (const auto& m : menu) {
            if (m.name == item) {
                orders.push_back(item);
                return "Order added: " + item;
            }
        }
        return "This item is currently unavailable";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& m : menu) {
                if (m.name == order) {
                    total += m.price;
                    break;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        double minPrice = numeric_limits<double>::max();
        string cheapest = "";
        for (const auto& m : menu) {
            if (m.price < minPrice) {
                minPrice = m.price;
                cheapest = m.name;
            }
        }
        return cheapest;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& m : menu) {
            if (m.type == "drink") drinks.push_back(m.name);
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> foods;
        for (const auto& m : menu) {
            if (m.type == "food") foods.push_back(m.name);
        }
        return foods;
    }
};

int main(int argc, char* argv[]) {
    vector<MenuItem> menu = {
        {"Latte", "drink", 3.5},
        {"Espresso", "drink", 2.5},
        {"Sandwich", "food", 5.0},
        {"Cake", "food", 4.0}
    };
    
    CoffeeShop shop("Java Cafe", menu);
    
    for (int i = 1; i < argc; i++) {
        cout << shop.addOrder(argv[i]) << endl;
    }
    
    cout << "Total Due: $" << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    
    cout << "Drinks Available: ";
    for (const auto& d : shop.drinksOnly()) cout << d << " ";
    cout << endl;
    
    cout << "Foods Available: ";
    for (const auto& f : shop.foodOnly()) cout << f << " ";
    cout << endl;
    
    while (!shop.listOrders().empty()) {
        cout << shop.fulfillOrder() << endl;
    }
    
    return 0;
}

