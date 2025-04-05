#include <iostream>

class Number {
private:
    int value;
public:
    Number(int v) : value(v) {}

    Number& operator--() { 
        value *= 4;
        return *this;
    }

    Number operator--(int) {
        Number temp = *this;
        value /= 4;
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& os, const Number& num) {
        os << num.value;
        return os;
    }
};

int main() {
    Number num(16);
    std::cout << "Original: " << num << "\n";
    --num;
    std::cout << "After Prefix -- : " << num << "\n";
    num--;
    std::cout << "After Postfix -- : " << num << "\n";
    return 0;
}

