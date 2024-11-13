#include <bitset>
#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <algorithm>
#include <sstream>
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

    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        int a[n], b[n];
        for (int &x: a) cin >> x;

        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(i);
            } else {
                while (!st.empty() && a[i] > a[st.top()]) {
                    b[st.top()] = a[i];
                    st.pop();
                }

                st.push(i);
            }
        }

        while (!st.empty()) {
            b[st.top()] = -1;
            st.pop();
        }

        for (auto it : b) {
            cout << it << " ";
        }

        cout << endl;
    }

    return 0;
}






