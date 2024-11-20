#include "libraries.cpp"
using namespace std;

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        map<int, int> mp;
        REP(i, n) {
            int x;
            cin >> x;
            mp[x]++;
        }

        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (it->second == 1) {
                cout << it->first << endl;
                break;
            }
        }
    }

    return 0;
}
