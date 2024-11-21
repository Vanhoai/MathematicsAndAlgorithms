#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

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

int main_dev() {
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
            cout << it.first << ": " << it.second << endl;
        }

        cout << endl;
    }

    return 0;
}