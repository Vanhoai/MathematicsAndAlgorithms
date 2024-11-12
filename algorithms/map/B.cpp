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
        int n, target; cin >> n >> target;
        int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

        map<int, int> mp;
        vii ans;

        for (int i = 0; i < n; ++i) {
            if (mp.find(target - a[i]) != mp.end()) {
                ans.push_back(make_pair(a[i], target - a[i]));
            }

            mp[a[i]] = 1;
        }

        for (auto it : ans) {
            cout << it.first << " " << it.second << endl;
        }

        cout << endl;
    }    

    return 0;
}