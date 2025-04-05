#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x);
    static Polynomial derivative(const Polynomial& p);
};

class Polynomial {
private:
    std::vector<int> coeffs;
    void trim() {
        while (!coeffs.empty() && coeffs.back() == 0) {
            coeffs.pop_back();
        }
    }

public:
    Polynomial() {}
    Polynomial(const std::vector<int>& c) : coeffs(c) { trim(); }

    Polynomial operator+(const Polynomial& other) const {
        std::vector<int> result(std::max(coeffs.size(), other.coeffs.size()), 0);
        for (size_t i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) result[i] += other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) const {
        std::vector<int> result(std::max(coeffs.size(), other.coeffs.size()), 0);
        for (size_t i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) result[i] -= other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) const {
        std::vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
        for (size_t i = 0; i < coeffs.size(); ++i) {
            for (size_t j = 0; j < other.coeffs.size(); ++j) {
                result[i + j] += coeffs[i] * other.coeffs[j];
            }
        }
        return Polynomial(result);
    }

    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
        if (p.coeffs.empty()) {
            os << "0";
            return os;
        }
        for (int i = p.coeffs.size() - 1; i >= 0; --i) {
            if (p.coeffs[i] != 0) {
                if (i != p.coeffs.size() - 1) os << (p.coeffs[i] > 0 ? " + " : " - ");
                else if (p.coeffs[i] < 0) os << "-";
                os << std::abs(p.coeffs[i]);
                if (i > 0) os << "x";
                if (i > 1) os << "^" << i;
            }
        }
        return os;
    }

    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0, power = 1;
    for (int coef : p.coeffs) {
        result += coef * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    if (p.coeffs.size() <= 1) return Polynomial({0});
    std::vector<int> deriv;
    for (size_t i = 1; i < p.coeffs.size(); ++i) {
        deriv.push_back(p.coeffs[i] * i);
    }
    return Polynomial(deriv);
}

int main() {
    Polynomial p1({2, -3, 1});
    Polynomial p2({1, 0, -1});
    std::cout << "p1: " << p1 << "\np2: " << p2 << "\np1 + p2: " << (p1 + p2) << "\n";
    std::cout << "Derivative of p1: " << PolynomialUtils::derivative(p1) << "\n";
    std::cout << "p1(2) = " << PolynomialUtils::evaluate(p1, 2) << "\n";
    return 0;
}

