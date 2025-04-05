#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

class BigInteger {
private:
    std::vector<int> digits;
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

public:
    BigInteger() : isNegative(false) { digits.push_back(0); }
    BigInteger(const std::string& num) {
        isNegative = (num[0] == '-');
        for (int i = num.size() - 1; i >= (isNegative ? 1 : 0); --i) {
            digits.push_back(num[i] - '0');
        }
        removeLeadingZeros();
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            int carry = 0, sum;
            size_t maxSize = std::max(digits.size(), other.digits.size());
            result.digits.resize(maxSize, 0);
            for (size_t i = 0; i < maxSize || carry; ++i) {
                sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                carry = sum / 10;
                result.digits[i] = sum % 10;
            }
            if (carry) result.digits.push_back(carry);
            return result;
        }
        return isNegative ? (other - (-*this)) : (*this - (-other));
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) return *this + (-other);
        if (*this == other) return BigInteger("0");
        bool resultNegative = *this < other;
        const BigInteger &larger = resultNegative ? other : *this;
        const BigInteger &smaller = resultNegative ? *this : other;
        BigInteger result;
        result.isNegative = resultNegative;
        result.digits.resize(larger.digits.size(), 0);
        int borrow = 0, diff;
        for (size_t i = 0; i < larger.digits.size(); ++i) {
            diff = larger.digits[i] - borrow - (i < smaller.digits.size() ? smaller.digits[i] : 0);
            borrow = diff < 0;
            if (borrow) diff += 10;
            result.digits[i] = diff;
        }
        result.removeLeadingZeros();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return digits == other.digits && isNegative == other.isNegative;
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) return isNegative;
        if (digits.size() != other.digits.size()) return (digits.size() < other.digits.size()) ^ isNegative;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) return (digits[i] < other.digits[i]) ^ isNegative;
        }
        return false;
    }

    bool operator>(const BigInteger& other) const { return other < *this; }
    bool operator<=(const BigInteger& other) const { return !(other < *this); }
    bool operator>=(const BigInteger& other) const { return !(*this < other); }

    BigInteger operator-() const {
        BigInteger result = *this;
        if (*this != BigInteger("0")) result.isNegative = !isNegative;
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const BigInteger& num) {
        if (num.isNegative) os << "-";
        for (int i = num.digits.size() - 1; i >= 0; --i) os << num.digits[i];
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BigInteger& num) {
        std::string input;
        is >> input;
        num = BigInteger(input);
        return is;
    }
};

int main() {
    BigInteger num1("999999999999999999999999999"), num2("1");
    std::cout << "Sum: " << (num1 + num2) << "\n";
    std::cout << "Difference: " << (num1 - num2) << "\n";
    return 0;
}

