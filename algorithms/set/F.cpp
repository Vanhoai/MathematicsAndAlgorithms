#include "../../libraries.cpp"
using namespace std;

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        set<int> s1;
        set<int> s2;

        REP(i, n) {
            int x;
            cin >> x;
            s1.insert(x);
        }

        REP(i, m) {
            int x;
            cin >> x;
            s2.insert(x);
        }

        int check = 1;
        for (auto it = s1.begin(); it != s1.end(); it++) {
            if (s2.find(*it) == s2.end()) {
                check = 0;
                break;
            }
        }

        if (check) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
