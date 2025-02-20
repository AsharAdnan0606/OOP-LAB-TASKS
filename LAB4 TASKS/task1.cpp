#include <iostream>
#include <cstdlib>
using namespace std;

class Matrix {
private:
    int rows, cols;
    double** data; 

public:
    Matrix() : rows(0), cols(0), data(nullptr) {}

    Matrix(int r, int c) : rows(r), cols(c) {
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols]();
        }
    }

    Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
        data = new double*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new double[cols];
            for (int j = 0; j < cols; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    Matrix(Matrix&& other) : rows(other.rows), cols(other.cols), data(other.data) {
        other.data = nullptr;
        other.rows = 0;
        other.cols = 0;
    }

    ~Matrix() {
        if (data) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    int getRows() { return rows; }

    int getCols() { return cols; }

    double& at(int r, int c) { return data[r][c]; }

    void fill(double value) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                data[i][j] = value;
            }
        }
    }

    Matrix transpose() {
        Matrix transposed(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                transposed.data[j][i] = data[i][j];
            }
        }
        return transposed;
    }

    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Usage: ./matrix <rows> <cols>" << endl;
        return 1;
    }
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    Matrix mat(rows, cols);
    mat.fill(5); 
    cout << "Original Matrix:" << endl;
    mat.print();
    Matrix transposed = mat.transpose();
    cout << "\nTransposed Matrix:" << endl;
    transposed.print();

    return 0;
}

