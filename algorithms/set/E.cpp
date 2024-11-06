#include "libraries.cpp"
using namespace std;

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        set<int> st;
        REP(i, n) {
            int x; cin >> x;
            st.insert(x);
        }

        for (auto it = st.begin(); it != st.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }

    return 0;
}
