#include <bitset>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
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
        map<ll, int> mp;
        for (int i = 0; i < n; i++) {
            ll x; cin >> x;
            mp[x]++;
        }

        int freq = INT_MIN, ans = INT_MIN;
        for (auto it : mp) {
            if (it.second >= freq) {
                freq = it.second;
                ans = it.first;
            }
        }

        cout << ans << endl;
    }

    return 0;
}






