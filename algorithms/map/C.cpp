#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
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

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }

        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            if (mp.find(x) != mp.end()) {
                mp.erase(x);
            }
        }

        for (auto it : mp) {
            cout << it.first << " ";
        }

        cout << endl;
    }

    return 0;
}
