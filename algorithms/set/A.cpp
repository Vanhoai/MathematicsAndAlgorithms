#include "../../libraries.cpp"
using namespace std;

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc;
    cin >> tc;
    while (tc--) {
        set<int> st;
        int n;
        cin >> n;
        REP(i, n) {
            int x;
            cin >> x;
            st.insert(x);
        }

        if (n != st.size()) {
            cout << "NO";
        } else {
            cout << "YES";
        }

        cout << endl;
    }

    return 0;
}
