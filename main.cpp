#include <iomanip>
#include <iostream>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> vii;

#define FAST_IO                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr)

#define PB push_back
#define MP make_pair

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
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }

        for (auto it : mp) {
            cout << it.first << " " << it.second << endl;
        }

        cout << endl;
    }

    return 0;
}
