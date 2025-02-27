#include <iostream>
#include <vector>

using namespace std;

struct Item {
    string name;
    string type;
    double price;
};

class CoffeeShop {
private:
    string name;
    vector<Item> menu;
    vector<string> orders;

public:
    CoffeeShop(string n, vector<Item> m) : name(n), menu(m) {}

    string addOrder(string itemName) {
        for (const auto& item : menu) {
            if (item.name == itemName) {
                orders.push_back(itemName);
                return "Order added!";
            }
        }
        return "This item is currently unavailable!";
    }

    string fulfillOrder() {
        if (!orders.empty()) {
            string item = orders.front();
            orders.erase(orders.begin());
            return "The " + item + " is ready!";
        }
        return "All orders have been fulfilled";
    }

    vector<string> listOrders() {
        return orders;
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& item : menu) {
                if (item.name == order) {
                    total += item.price;
                }
            }
        }
        return total;
    }

    string cheapestItem() {
        if (menu.empty()) return "No items available";
        Item cheapest = menu[0];
        for (const auto& item : menu) {
            if (item.price < cheapest.price) {
                cheapest = item;
            }
        }
        return cheapest.name;
    }

    vector<string> drinksOnly() {
        vector<string> drinks;
        for (const auto& item : menu) {
            if (item.type == "drink") {
                drinks.push_back(item.name);
            }
        }
        return drinks;
    }

    vector<string> foodOnly() {
        vector<string> food;
        for (const auto& item : menu) {
            if (item.type == "food") {
                food.push_back(item.name);
            }
        }
        return food;
    }
};

int main() {
    vector<Item> menu = {
        {"Coffee", "drink", 2.5},
        {"Tea", "drink", 2.0},
        {"Sandwich", "food", 5.0},
        {"Cake", "food", 3.0}
    };

    CoffeeShop shop("Cafe Delight", menu);
    
    cout << shop.addOrder("Coffee") << endl;
    cout << shop.addOrder("Pizza") << endl;
    
    cout << shop.fulfillOrder() << endl;
    cout << shop.fulfillOrder() << endl;
    
    cout << "Total Due: " << shop.dueAmount() << endl;
    cout << "Cheapest Item: " << shop.cheapestItem() << endl;
    
    vector<string> drinks = shop.drinksOnly();
    cout << "Drinks: ";
    for (const auto& d : drinks) cout << d << " ";
    cout << endl;
    
    vector<string> food = shop.foodOnly();
    cout << "Food: ";
    for (const auto& f : food) cout << f << " ";
    cout << endl;
    
    return 0;
}
