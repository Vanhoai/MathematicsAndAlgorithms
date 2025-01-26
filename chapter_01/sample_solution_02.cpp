#include <iostream>
using namespace std;

// 6
// -2 11 -4 13 -5 2
// ans: 20

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;

    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            ans = max(ans, sum);
        }
    }

    cout << ans << endl;
    return 0;
}