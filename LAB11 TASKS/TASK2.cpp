#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Custom exception for dimension mismatch
class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "DimensionMismatchException: Matrix dimensions do not match for operation.";
    }
};

// Matrix class template
template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows, cols;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c), data(r, vector<T>(c)) {}

    // Safe element access with bounds checking
    T& operator()(size_t i, size_t j) {
        if (i >= rows || j >= cols) {
            throw out_of_range("Index out of bounds");
        }
        return data[i][j];
    }

    const T& operator()(size_t i, size_t j) const {
        if (i >= rows || j >= cols) {
            throw out_of_range("Index out of bounds");
        }
        return data[i][j];
    }

    // Getters
    size_t getRows() const { return rows; }
    size_t getCols() const { return cols; }

    // Matrix addition
    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            throw DimensionMismatchException();
        }

        Matrix result(rows, cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < cols; ++j)
                result(i, j) = data[i][j] + other(i, j);

        return result;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows) {
            throw DimensionMismatchException();
        }

        Matrix result(rows, other.cols);
        for (size_t i = 0; i < rows; ++i)
            for (size_t j = 0; j < other.cols; ++j)
                for (size_t k = 0; k < cols; ++k)
                    result(i, j) += data[i][k] * other(k, j);

        return result;
    }

    // Print matrix
    void print() const {
        for (const auto& row : data) {
            for (const auto& val : row)
                cout << val << " ";
            cout << "\n";
        }
    }
};

// Demo
int main() {
    try {
        Matrix<int> A(2, 2), B(2, 2);

        // Initializing A
        A(0, 0) = 1; A(0, 1) = 2;
        A(1, 0) = 3; A(1, 1) = 4;

        // Initializing B
        B(0, 0) = 5; B(0, 1) = 6;
        B(1, 0) = 7; B(1, 1) = 8;

        cout << "Matrix A:\n"; A.print();
        cout << "Matrix B:\n"; B.print();

        Matrix<int> C = A + B;
        cout << "A + B:\n"; C.print();

        Matrix<int> D = A * B;
        cout << "A * B:\n"; D.print();

        // Trigger dimension mismatch
        Matrix<int> E(3, 2);
        Matrix<int> F = A + E;  // This will throw

    } catch (const DimensionMismatchException& e) {
        cerr << "Error: " << e.what() << endl;
    } catch (const out_of_range& e) {
        cerr << "Bounds Error: " << e.what() << endl;
    }

    return 0;
}

