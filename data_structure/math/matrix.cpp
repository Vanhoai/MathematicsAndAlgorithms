
#include "libraries.cpp"
using namespace std;

double calculateDeterminant(vvd matrix, int n) {
    double determinant = 1.0;
    REP(i, n) {
        if (matrix[i][i] == 0) {
            bool swapped = false;

            FOR(j, i + 1, n - 1) {
                if (matrix[j][i] != 0) {
                    swap(matrix[i], matrix[j]);
                    determinant *= -1;
                    swapped = true;
                    break;
                }
            }
            if (!swapped)
                return 0;
        }

        FOR(j, i + 1, n - 1) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n; k++)
                matrix[j][k] -= factor * matrix[i][k];
        }

        determinant *= matrix[i][i];
    }
    return determinant;
}

int main_dev() {
    int n;
    cin >> n;
    vvd matrix(n, vector<double>(n));

    REP(i, n)
    REP(j, n) cin >> matrix[i][j];

    double determinant = calculateDeterminant(matrix, n);
    cout << "Determinant: " << determinant << endl;

    return 0;
}