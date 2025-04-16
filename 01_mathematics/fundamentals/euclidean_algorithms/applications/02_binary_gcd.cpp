#include <iostream>
using namespace std;

int binary_gcd(int a, int b) {
    if (!a || !b)
        return a | b;

    unsigned shift = __builtin_ctz(a | b);
    a = a >> __builtin_ctz(a);
    do {
        b = b >> __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);

    return a << shift;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int a, b;
    cin >> a >> b;
    cout << binary_gcd(a, b) << endl;

    return 0;
}
