#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

// ========== Task 4: Template Inheritance with Multiplication ==========
template <typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    T multiplyBase() const {
        return a * b;
    }
};

template <typename T>
class Derived : public Base<T> {
private:
    T c, d;
public:
    Derived(T x, T y, T m, T n) : Base<T>(x, y), c(m), d(n) {}

    T multiplyDerived() const {
        return c * d;
    }

    void displayMultiplications() const {
        cout << "Base class multiplication: " << this->multiplyBase() << endl;
        cout << "Derived class multiplication: " << this->multiplyDerived() << endl;
    }
};

// ========== Task 5: Stack Class Template with Exception ==========
class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "StackUnderflowException: Cannot pop or access top from empty stack.";
    }
};

template <typename T>
class Stack {
private:
    vector<T> data;
public:
    void push(const T& value) {
        data.push_back(value);
    }

    void pop() {
        if (data.empty()) throw StackUnderflowException();
        data.pop_back();
    }

    T top() const {
        if (data.empty()) throw StackUnderflowException();
        return data.back();
    }

    bool empty() const {
        return data.empty();
    }
};

// ========== Main Demo ==========
int main() {
    cout << "=== Task 4: Template Inheritance Demo ===" << endl;
    Derived<int> obj(2, 3, 4, 5);
    obj.displayMultiplications();

    cout << "\n=== Task 5: Stack Template with Exception Demo ===" << endl;
    Stack<int> s;
    try {
        s.push(10);
        s.push(20);
        cout << "Top of stack: " << s.top() << endl;
        s.pop();
        cout << "Top after pop: " << s.top() << endl;
        s.pop();
        cout << "Trying one more pop (should throw)..." << endl;
        s.pop(); // This will throw
    } catch (const StackUnderflowException& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

