#include <iostream>
using namespace std;

class Car {
private:
    int *engine_hp;
    int *seating_capacity;
    int *no_of_speakers;

public:
    Car() {
        engine_hp = new int(0);
        seating_capacity = new int(0);
        no_of_speakers = new int(0);
    }

    Car(int hp, int cap, int num) {
        engine_hp = new int(hp);
        seating_capacity = new int(cap);
        no_of_speakers = new int(num);
    }

    ~Car() {
        delete engine_hp;
        delete seating_capacity;
        delete no_of_speakers;
    }

    void display_data() const {
        cout << "HP: " << *engine_hp << endl;
        cout << "Seating Capacity: " << *seating_capacity << endl;
        cout << "Number of Speakers: " << *no_of_speakers << endl;
    }

    void set_data(int hp, int cap, int num) const {
        Car *nonConstThis = const_cast<Car *>(this);
        *(nonConstThis->engine_hp) = hp;
        *(nonConstThis->seating_capacity) = cap;
        *(nonConstThis->no_of_speakers) = num;
    }
};

int main() {
    Car car1(10000, 4, 2);

    cout << "Before modification:\n";
    car1.display_data();

    car1.set_data(5000, 5, 5);

    cout << "\nAfter modification:\n";
    car1.display_data();

    return 0;
}

