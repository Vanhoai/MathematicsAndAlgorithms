#include <iostream>
using namespace std;

int maxRecursive(int *a, int l, int r) {
    if (l == r) return a[l];
    else if (l == r - 1) return a[l] > a[r] ? a[l] : a[r];
    else {
        int m = (l + r) / 2;
        int maxLeft = maxRecursive(a, l, m);
        int maxRight = maxRecursive(a, m + 1, r);
        return max(maxLeft, maxRight);
    }
}

// 9
// 4 5 1 2 8 9 10 3 6

int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << "Max: " << maxRecursive(a, 0, n - 1) << endl;
    return 0;
}