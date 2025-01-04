#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

struct Matrix {
    vector<vector<double>> data;
    int rows, cols;

    Matrix(int rows, int cols, double init = 0.0)
        : rows(rows), cols(cols), data(rows, vector<double>(cols, init)) {}

    Matrix(const vector<vector<double>> &d)
        : rows(d.size()), cols(d[0].size()), data(d) {}

    void print() const {
        for (const auto &row : data) {
            for (double value : row) {
                cout << setw(10) << fixed << setprecision(4) << value << " ";
            }
            cout << endl;
        }
    }

    Matrix operator+(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols)
            throw runtime_error("Matrix dimensions must match for addition.");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator-(const Matrix &other) const {
        if (rows != other.rows || cols != other.cols)
            throw runtime_error(
                "Matrix dimensions must match for subtraction.");
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] - other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix &other) const {
        if (cols != other.rows)
            throw runtime_error(
                "Matrix dimensions must match for multiplication.");
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < other.cols; ++j) {
                for (int k = 0; k < cols; ++k) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    Matrix operator*(double scalar) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[i][j] = data[i][j] * scalar;
        return result;
    }

    Matrix operator/(double scalar) const {
        if (scalar == 0)
            throw runtime_error("Cannot divide by zero.");
        return (*this) * (1.0 / scalar);
    }

    Matrix transpose() const {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result.data[j][i] = data[i][j];
        return result;
    }

    Matrix inverse() const {
        if (rows != cols)
            throw runtime_error("Matrix must be square to calculate inverse.");
        int n = rows;
        Matrix augmented(n, 2 * n);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                augmented.data[i][j] = data[i][j];
            }
            augmented.data[i][i + n] = 1.0;
        }

        for (int i = 0; i < n; ++i) {
            double maxElement = abs(augmented.data[i][i]);
            int maxRow = i;
            for (int k = i + 1; k < n; ++k) {
                if (abs(augmented.data[k][i]) > maxElement) {
                    maxElement = abs(augmented.data[k][i]);
                    maxRow = k;
                }
            }

            swap(augmented.data[i], augmented.data[maxRow]);

            if (augmented.data[i][i] == 0)
                throw runtime_error(
                    "Matrix is singular and cannot be inverted.");

            double diag = augmented.data[i][i];
            for (int j = 0; j < 2 * n; ++j) {
                augmented.data[i][j] /= diag;
            }

            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    double factor = augmented.data[k][i];
                    for (int j = 0; j < 2 * n; ++j) {
                        augmented.data[k][j] -= factor * augmented.data[i][j];
                    }
                }
            }
        }

        Matrix result(n, n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                result.data[i][j] = augmented.data[i][j + n];
            }
        }
        return result;
    }

    double determinant() const {
        if (rows != cols)
            throw runtime_error(
                "Matrix must be square to calculate determinant.");

        int n = rows;
        Matrix temp = *this;
        double det = 1;

        for (int i = 0; i < n; ++i) {
            int pivotRow = i;
            for (int j = i + 1; j < n; ++j) {
                if (abs(temp.data[j][i]) > abs(temp.data[pivotRow][i])) {
                    pivotRow = j;
                }
            }

            if (temp.data[pivotRow][i] == 0)
                return 0;

            if (pivotRow != i) {
                swap(temp.data[i], temp.data[pivotRow]);
                det = -det;
            }

            det *= temp.data[i][i];

            for (int j = i + 1; j < n; ++j) {
                double factor = temp.data[j][i] / temp.data[i][i];
                for (int k = i; k < n; ++k) {
                    temp.data[j][k] -= factor * temp.data[i][k];
                }
            }
        }

        return det;
    }
};

Matrix operator*(double scalar, const Matrix &matrix) {
    return matrix * scalar;
}