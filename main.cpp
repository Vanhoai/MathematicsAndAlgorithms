#include "./libraries.cpp"
#include <iostream>
using namespace std;

int main() {
    IOS;
    IO;

    int n;
    cin >> n;
    int a[n];

    for (int &x : a)
        cin >> x;

    int s[n];
    s[0] = a[0];
    int ans = a[0];
    for (int i = 1; i < n; i++) {
        if (s[i - 1] > 0) {
            s[i] = s[i - 1] + a[i];
        } else {
            s[i] = a[i];
        }

        ans = max(ans, s[i]);
    }

    cout << ans << endl;
    return 0;
}
