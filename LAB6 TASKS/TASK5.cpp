#include<iostream>
using namespace std;

class Vehicle {
    public:
        float price;
        Vehicle(float p) : price(p) {}
};

class Car : public Vehicle {
    public:
        int seatingCapacity;
        int numberOfDoors;
        string fuelType;

        Car(float p, int seating, int doors, string fuel) : Vehicle(p), seatingCapacity(seating), numberOfDoors(doors), fuelType(fuel) {}
};

class Motorcycle : public Vehicle {
    public:
        int cylinders;
        int gears;
        int wheels;

        Motorcycle(float p, int c, int g, int w) : Vehicle(p), cylinders(c), gears(g), wheels(w) {}
};

class Audi : public Car {
    public:
        string modelType;
        Audi(float p, int seating, int doors, string fuel, string model) : Car(p, seating, doors, fuel), modelType(model) {}
        
        void displayDetails() {
            cout << "Audi Car Details:\n";
            cout << "Price: " << price << endl;
            cout << "Seating Capacity: " << seatingCapacity << endl;
            cout << "Number of Doors: " << numberOfDoors << endl;
            cout << "Fuel Type: " << fuelType << endl;
            cout << "Model Type: " << modelType << endl;
        }
};

class Yamaha : public Motorcycle {
    public:
        string makeType;
        Yamaha(float p, int c, int g, int w, string make) : Motorcycle(p, c, g, w), makeType(make) {}
        
        void displayDetails() {
            cout << "Yamaha Motorcycle Details:\n";
            cout << "Price: " << price << endl;
            cout << "Cylinders: " << cylinders << endl;
            cout << "Gears: " << gears << endl;
            cout << "Wheels: " << wheels << endl;
            cout << "Make Type: " << makeType << endl;
        }
};

int main() {
    Audi audiCar(50000, 5, 4, "Petrol", "A8");
    Yamaha yamahaBike(15000, 2, 6, 2, "Sports");
    
    audiCar.displayDetails();
    cout << "---------------------------" << endl;
    yamahaBike.displayDetails();
    
    return 0;
}

