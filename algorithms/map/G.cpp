#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        int a[26];
        memset(a, 0, sizeof(a));
        for (char it : s) {
            a[tolower(it) - 'a'] = 1;
        }

        int check = 1;
        for (int i = 0; i < 26; i++) {
            if (!a[i]) {
                check = 0;
                break;
            }
        }

        cout << check << endl;
    }

    return 0;
}
