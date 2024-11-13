#include <bitset>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long ll;        // Alias for long long
typedef pair<int, int> pi;   // Alias for pair of integers
typedef vector<pi> vii;      // Alias for vector of integers

#define FAST_IO                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr)

void READ_WRITE_FILE() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int a[n];
        for (int &x: a) cin >> x;

        for (int i = 0; i < n - 1; i++) {
            int max = -1;
            for (int k = i + 1; k < n; k++) {
                if (a[k] > a[i]) {
                    max = a[k];
                    break;
                }
            }

            cout << max << " ";
        }

        cout << -1 << endl;
    }

    return 0;
}






