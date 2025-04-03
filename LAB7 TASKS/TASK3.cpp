#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode, currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}
    virtual double convertToBase() { return amount * exchangeRate; }
    virtual double convertTo(Currency &targetCurrency) { return convertToBase() / targetCurrency.exchangeRate; }
    virtual void displayCurrency() {
        cout << "Currency: " << currencyCode << " (" << currencySymbol << ") Amount: " << amount << "\n";
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}
    void displayCurrency() override {
        cout << "USD: $" << amount << "\n";
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.1) {}
    void displayCurrency() override {
        cout << "EUR: €" << amount << "\n";
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", "?", 0.013) {}
    void displayCurrency() override {
        cout << "INR: ?" << amount << "\n";
    }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(100);
    
    d.displayCurrency();
    cout << "Converted to EUR: " << d.convertTo(e) << "€\n";
    cout << "Converted to INR: " << d.convertTo(r) << "?\n\n";
    
    e.displayCurrency();
    cout << "Converted to USD: " << e.convertTo(d) << "$\n";
    cout << "Converted to INR: " << e.convertTo(r) << "?\n\n";
    
    r.displayCurrency();
    cout << "Converted to USD: " << r.convertTo(d) << "$\n";
    cout << "Converted to EUR: " << r.convertTo(e) << "€\n";
    
    return 0;
}

