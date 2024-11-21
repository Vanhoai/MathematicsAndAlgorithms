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

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc; cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);

        stack<char> st;
        int check = 1;
        for (char it : s) {
            if (it == '(' || it == '[' || it == '{') {
                st.push(it);
            } else {
                if (st.empty()) {
                    check = 0;
                    break;
                }

                char t = st.top();
                if (it == ')') {
                    if (t == '(') {
                        st.pop();
                    }  else {
                        check = 0;
                        break;
                    }
                }

                if (it == ']') {
                    if (t == '[') {
                        st.pop();
                    }  else {
                        check = 0;
                        break;
                    }
                }

                if (it == '}') {
                    if (t == '{') {
                        st.pop();
                    }  else {
                        check = 0;
                        break;
                    }
                }
            }
        }

        if (st.empty()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}






