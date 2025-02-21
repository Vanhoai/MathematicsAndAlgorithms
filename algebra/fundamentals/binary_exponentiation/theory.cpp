#include "bits/stdc++.h"
using namespace std;

/**
 * Binary Exponentiation
 *
 * a^n = {
 *      1                   if n == 0
 *      a^n/2 * a^n/2       if n > 0 and n even
 *      a^n/2 * a^n/2 * a   if n > 0 and n old
 * }
 */

long long binpow_recursive(long long a, long long n) {
    if (n == 0)
        return 1;
    long long res = binpow_recursive(a, n / 2);
    if (n % 2)
        return res * res * a;
    else
        return res * res;
}

long long binpow(long long a, long long n) {
    long long res = 1;

    while (n > 0) {
        if (n & 1)
            res = res * a;

        a = a * a;
        n = n >> 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    long long a, n;
    cin >> a >> n;
    cout << binpow_recursive(a, n) << endl;
    cout << binpow(a, n) << endl;

    return 0;
}
