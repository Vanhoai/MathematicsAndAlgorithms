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
        set<int> st;
        REP(i, n) {
            int x;
            cin >> x;
            st.insert(x);
        }

        cout << st.size() << endl;
    }

    return 0;
}
