#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9 + 7;
#define FOR(i, a, b) for (int i = a; i <= (b); i++)
typedef vector<vector<int>> vvi;

vvi multiply(vvi &a, vvi &b, int n) {
    vvi res(n, vector<int>(n, 0));
    FOR(i, 0, n - 1) FOR(j, 0, n - 1) FOR(k, 0, n - 1) {
        res[i][j] = (res[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
    }

    return res;
}

vvi matrixExponentiation(vvi base, int k, int n) {
    vvi res(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1;

    while (k > 0) {
        if (k % 2 == 1) res = multiply(res, base, n);
        base = multiply(base, base, n);
        k /= 2;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, k; cin >> n >> k;
    vvi adj(n, vector<int>(n));
    FOR(i, 0, n - 1) FOR(j, 0, n - 1) cin >> adj[i][j];

    vvi res = matrixExponentiation(adj, k, n);
    FOR(i, 0, n - 1) {
        FOR(j, 0, n - 1) cout << res[i][j] << " ";
        cout << endl;
    }

    return 0;
}







