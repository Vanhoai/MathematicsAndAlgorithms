#include <iostream>
#include <map>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define READ_WRITE_FILE freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout)

int main() {
    FAST_IO;
    READ_WRITE_FILE;

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

        for (auto [F, S]: mp) {
            cout << F << " " << S << endl;
        }

        cout << endl;
    }

    return 0;
}
























