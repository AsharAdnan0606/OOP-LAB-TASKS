#include <iostream>
#include <string>

// Abstract class Car
class Car {
protected:
    std::string model;
    double price;

public:
    // Constructor
    Car(std::string m, double p) : model(m), price(p) {}

    // Getter for model
    std::string getModel() const {
        return model;
    }

    // Setter for model
    void setModel(const std::string& m) {
        model = m;
    }

    // Getter for price
    double getPrice() const {
        return price;
    }

    // Abstract setter for price (must be implemented by subclasses)
    virtual void setPrice(double p) = 0;

    // Virtual destructor
    virtual ~Car() {}
};

// Subclass Color that implements setPrice
class Color : public Car {
private:
    std::string color;

public:
    // Constructor
    Color(std::string m, double p, std::string c) : Car(m, p), color(c) {}

    // Getter for color
    std::string getColor() const {
        return color;
    }

    // Setter for color
    void setColor(const std::string& c) {
        color = c;
    }

    // Override setPrice method to adjust price based on color
    void setPrice(double p) override {
        if (color == "red") {
            price = p + 500; // Red cars are more expensive by $500
        } else {
            price = p;
        }
    }

    // Display information about the car
    void displayInfo() const {
        std::cout << "Model: " << model << "\nColor: " << color << "\nPrice: $" << price << std::endl;
    }
};

// Subclass Company that implements setPrice
class Company : public Car {
private:
    std::string company;

public:
    // Constructor
    Company(std::string m, double p, std::string comp) : Car(m, p), company(comp) {}

    // Getter for company
    std::string getCompany() const {
        return company;
    }

    // Setter for company
    void setCompany(const std::string& comp) {
        company = comp;
    }

    // Override setPrice method to adjust price based on company
    void setPrice(double p) override {
        if (company == "Tesla") {
            price = p + 10000; // Tesla cars are more expensive by $10,000
        } else {
            price = p;
        }
    }

    // Display information about the car
    void displayInfo() const {
        std::cout << "Model: " << model << "\nCompany: " << company << "\nPrice: $" << price << std::endl;
    }
};

int main() {
    // Create instances of Color and Company subclasses
    Color car1("Model X", 40000, "red");
    Company car2("Model S", 70000, "Tesla");

    // Set prices using setPrice method
    car1.setPrice(40000);
    car2.setPrice(70000);

    // Display car information
    car1.displayInfo();
    car2.displayInfo();

    return 0;
}

