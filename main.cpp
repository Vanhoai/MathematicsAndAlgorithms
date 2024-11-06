#include <iostream>
#include <map>
using namespace std;

#define F  first       // Short for accessing first element of pair
#define S  second      // Short for accessing second element of pair
#define PB push_back   // Push back to vector
#define MP make_pair   // Make pair of two elementsx

#define FAST_IO                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr)

#define READ_WRITE_FILE read

void read() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mp[x]++;
        }

        for (pair<int, int> it: mp) {
            cout << it.first << ": " << it.second << endl;
        }
    }

    return 0;
}