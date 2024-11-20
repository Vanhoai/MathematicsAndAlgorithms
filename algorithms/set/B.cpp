#include "libraries.cpp"
using namespace std;

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;

        set<int> st;
        set<int> res;

        REP(i, n + m) {
            int x;
            cin >> x;
            if (st.find(x) == st.end()) {
                st.insert(x);
            } else {
                res.insert(x);
            }
        }

        for (auto it = res.begin(); it != res.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }

    return 0;
}
