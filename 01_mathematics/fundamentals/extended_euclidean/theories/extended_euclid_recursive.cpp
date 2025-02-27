#include "bits/stdc++.h"
using namespace std;

int gcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return g;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b; cin >> a >> b;
    int x, y;
    int d = gcd(a, b, x, y);
    cout << d << endl;
    cout << "x = " << x << " y = " << y << endl;
    return 0;
}
