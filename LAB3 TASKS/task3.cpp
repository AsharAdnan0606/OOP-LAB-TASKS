#include <iostream>
using namespace std;

class Glass {
public:
    int LiquidLevel;

    Glass() {
        LiquidLevel = 200;
    }

    void Drink(int milliliters) {
   
        LiquidLevel -= milliliters;

        if (LiquidLevel < 100) {
            Refill();
        }
    }


    void Refill() {
        LiquidLevel = 200;
    }
};

int main() {
    
    Glass myGlass;
 
    while (true) {
        cout << "Current liquid level: " << myGlass.LiquidLevel << " ml" << endl;
        cout << "Enter amount of liquid to drink (in ml) or type 'exit' to stop:";

        string input;
        cin >> input;

        
        if (input == "exit") {
            break;
        }     
        try {
            int amountDrank = stoi(input);
            
            myGlass.Drink(amountDrank);
        } catch (const invalid_argument& e) {
            cout << "Invalid input. Please enter a valid number or 'exit'." << endl;
        }
    }

    return 0;
}

