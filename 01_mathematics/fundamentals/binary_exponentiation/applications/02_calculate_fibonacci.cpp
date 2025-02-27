#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;
struct Matrix {
    long long m[2][2];
    Matrix operator*(const Matrix &b) const {
        Matrix res{};
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) {
                res.m[i][j] = 0;
                for (int k = 0; k < 2; k++)
                    res.m[i][j] = (res.m[i][j] + m[i][k] * b.m[k][j]) % MOD;
            }
        return res;
    }
};

Matrix power(Matrix a, long long n) {
    Matrix res = {1, 0, 0, 1};
    
    while (n > 0) {
        if (n & 1) 
            res = res * a;

        a = a * a;
        n = n >> 1;
    }

    return res;
}

long long fibonacci(long long n) {
    if (n == 0) return 0;
    Matrix F = {1, 1, 1, 0};
    Matrix res = power(F, n - 1);
    return res.m[0][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n; cin >> n;
    cout << fibonacci(n) << endl;

    return 0;
}
