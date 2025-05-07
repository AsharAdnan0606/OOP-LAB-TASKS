#include <iostream>
#include <any>
#include <stdexcept>
using namespace std;

// Custom exception class
class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Incorrect type requested!";
    }
};

// TypeSafeContainer template
class TypeSafeContainer {
private:
    std::any data;

public:
    // Store any type
    template<typename T>
    void store(const T& value) {
        data = value;
    }

    // Retrieve only if type matches, else throw
    template<typename T>
    T get() const {
        if (!data.has_value() || data.type() != typeid(T)) {
            throw BadTypeException();
        }
        return std::any_cast<T>(data);
    }
};

// Demo
int main() {
    TypeSafeContainer container;

    try {
        container.store<int>(42);
        cout << "Stored int: " << container.get<int>() << endl;

        container.store<string>("hello");
        cout << "Stored string: " << container.get<string>() << endl;

        // Intentional wrong type retrieval to trigger exception
        cout << "Trying to get int from string container..." << endl;
        cout << container.get<int>() << endl; // This should throw
    } catch (const BadTypeException& e) {
        cerr << "Caught exception: " << e.what() << endl;
    }

    return 0;
}

