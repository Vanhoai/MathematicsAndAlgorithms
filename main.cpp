#include <iostream>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>
using namespace std;

// input: {1, 2, 4, 5, 7, 6} n = 6
// output is missing number is 3

// 2
// 6
// 1 2 4 5 7 6
// 5
// 1 2 3 4 5

void solve() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        int expected_sum = (n + 1) * (n + 2) / 2;
        int actual_sum = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            actual_sum += x;
        }

        int ans = expected_sum - actual_sum;
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}