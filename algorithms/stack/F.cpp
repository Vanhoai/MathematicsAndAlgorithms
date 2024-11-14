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

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> vii;

#define FAST_IO                     \
    ios::sync_with_stdio(false);    \
    cin.tie(nullptr);               \
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
        int a[n]; for (int &x : a) cin >> x;

        stack<int> st;
        int res = INT_MIN;
        int i = 0;
        while (i < n) {
            if (st.empty() || a[i] >= a[st.top()]) {
                st.push(i++);
            } else {
                int idx = st.top();
                st.pop();

                if (st.empty()) {
                    res = max(res, i * a[idx]);
                } else {
                    res = max(res, (i - st.top() - 1) * a[idx]);
                }
            }
         }

        while (!st.empty()) {
            int idx = st.top();
            st.pop();

            if (st.empty()) {
                res = max(res, i * a[idx]);
            } else {
                res = max(res, (i - st.top() - 1) * a[idx]);
            }
        }

        cout << res << endl;
    }

    return 0;
}























