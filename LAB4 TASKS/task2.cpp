#include <iostream>
#include <cstdlib> 

using namespace std;

class Polynomial {
private:
    int degree;
    double* coeffs;

public:
    Polynomial() : degree(0) {
        coeffs = new double[1]();
    }

    Polynomial(int deg, const double* coefArr) : degree(deg) {
        coeffs = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coeffs[i] = coefArr[i];
        }
    }

    Polynomial(const Polynomial& other) : degree(other.degree) {
        coeffs = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coeffs[i] = other.coeffs[i];
        }
    }

    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coeffs(other.coeffs) {
        other.coeffs = nullptr;
        other.degree = 0;
    }

    ~Polynomial() {
        delete[] coeffs;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0, power = 1;
        for (int i = 0; i <= degree; i++) {
            result += coeffs[i] * power;
            power *= x;
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double newCoeffs[maxDegree + 1] = {0};

        for (int i = 0; i <= degree; i++) newCoeffs[i] += coeffs[i];
        for (int i = 0; i <= other.degree; i++) newCoeffs[i] += other.coeffs[i];

        return Polynomial(maxDegree, newCoeffs);
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double newCoeffs[newDegree + 1] = {0};

        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                newCoeffs[i + j] += coeffs[i] * other.coeffs[j];
            }
        }

        return Polynomial(newDegree, newCoeffs);
    }

    void print() const {
        for (int i = degree; i >= 0; i--) {
            cout << coeffs[i] << "x^" << i;
            if (i > 0) cout << " + ";
        }
        cout << endl;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 4) {
        return 1;
    }

    int index = 1;

    int deg1 = atoi(argv[index++]);
    double* coeffs1 = new double[deg1 + 1];
    for (int i = 0; i <= deg1; i++) {
        coeffs1[i] = atof(argv[index++]);
    }

    int deg2 = atoi(argv[index++]);
    double* coeffs2 = new double[deg2 + 1];
    for (int i = 0; i <= deg2; i++) {
        coeffs2[i] = atof(argv[index++]);
    }

    Polynomial p1(deg1, coeffs1);
    Polynomial p2(deg2, coeffs2);

    cout << "Polynomial 1: ";
    p1.print();
    cout << "Polynomial 2: ";
    p2.print();

    Polynomial sum = p1.add(p2);
    cout << "Sum: ";
    sum.print();

    Polynomial product = p1.multiply(p2);
    cout << "Product: ";
    product.print();

    double x = 2;
    cout << "p1(" << x << ") = " << p1.evaluate(x) << endl;

    delete[] coeffs1;
    delete[] coeffs2;

    return 0;
}

