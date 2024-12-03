#include <vector>
using namespace std;

vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
    int R1 = A.size();
    int C1 = A[0].size();
    int R2 = B.size();
    int C2 = B[0].size();

    if (C1 != R2) return vector<vector<int>>();

    vector<vector<int>> ans(R1, vector<int>(C2, 0));

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            for (int k = 0; k < C1; k++) {
                ans[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return ans;
}

double calculateDeterminant(vector<vector<double>> &matrix) {
    int n = matrix.size();
    double determinant = 1;
    int swapCount = 0;

    for (int i = 0; i < n; ++i) {
        int pivotRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (fabs(matrix[j][i]) > fabs(matrix[pivotRow][i])) {
                pivotRow = j;
            }
        }

        if (fabs(matrix[pivotRow][i]) < 1e-9) {
            return 0;
        }

        if (pivotRow != i) {
            swap(matrix[i], matrix[pivotRow]);
            ++swapCount;
        }

        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }

        determinant *= matrix[i][i];
    }

    if (swapCount % 2 != 0) {
        determinant = -determinant;
    }

    return determinant;
}

bool inverseMatrix(vector<vector<double>>& matrix, vector<vector<double>>& inverse) {
    int n = matrix.size();

    inverse.resize(n, vector<double>(n, 0));
    for (int i = 0; i < n; ++i) {
        inverse[i][i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int pivotRow = i;
        for (int j = i + 1; j < n; ++j) {
            if (fabs(matrix[j][i]) > fabs(matrix[pivotRow][i])) {
                pivotRow = j;
            }
        }

        if (fabs(matrix[pivotRow][i]) < 1e-9) {
            return false;
        }

        if (pivotRow != i) {
            swap(matrix[i], matrix[pivotRow]);
            swap(inverse[i], inverse[pivotRow]);
        }

        double pivot = matrix[i][i];
        for (int j = 0; j < n; ++j) {
            matrix[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double factor = matrix[j][i];
                for (int k = 0; k < n; ++k) {
                    matrix[j][k] -= factor * matrix[i][k];
                    inverse[j][k] -= factor * inverse[i][k];
                }
            }
        }
    }

    return true;
}
