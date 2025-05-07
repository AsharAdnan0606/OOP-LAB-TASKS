#include <iostream>
#include <stdexcept>
using namespace std;

// Custom exception
class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "ArrayIndexOutOfBounds: Index out of valid range.";
    }
};

// Template class SafeArray<T>
template <typename T>
class SafeArray {
private:
    T* arr;
    int size;

public:
    SafeArray(int s) {
        if (s <= 0) throw invalid_argument("Size must be positive");
        size = s;
        arr = new T[size];
    }

    // Overloaded operator[] with bounds checking
    T& operator[](int index) {
        if (index < 0 || index >= size) {
            throw ArrayIndexOutOfBounds();
        }
        return arr[index];
    }

    // Getter for size
    int getSize() const {
        return size;
    }

    // Destructor
    ~SafeArray() {
        delete[] arr;
    }
};

// Demo
int main() {
    try {
        SafeArray<int> arr(5);

        // Initialize
        for (int i = 0; i < arr.getSize(); ++i) {
            arr[i] = i * 10;
        }

        // Print
        cout << "Array elements:\n";
        for (int i = 0; i < arr.getSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        // Trigger out of bounds access
        cout << "Accessing arr[6]...\n";
        cout << arr[6] << endl; // Should throw

    } catch (const ArrayIndexOutOfBounds& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "General Error: " << e.what() << endl;
    }

    return 0;
}

