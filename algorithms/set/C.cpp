#include "libraries.cpp"
using namespace std;

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc; cin >> tc;
    while (tc --) {
        int n, m; cin >> n >> m;
        set<int> st;
        REP(i, n) {
            int x; cin >> x;
            st.insert(x);
        }

        REP(i, m) {
            int x; cin >> x;
            if (st.find(x) != st.end()) {
                st.erase(x);
            }
        }

        for (auto it = st.begin(); it != st.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
    

    return 0;
}
