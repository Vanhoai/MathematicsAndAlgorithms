#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> vii;

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

int bin2Dec(string s) {
    int sum = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        int bit = s[size - i - 1] - '0'; // Convert char to int
        sum += bit * (1 << i); // Use bit shifting for powers of 2
    }
    return sum;
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc;
    cin >> tc;
    while (tc--) {
        int t;
        cin >> t;
        queue<string> q;
        vector<string> ans;
        ans.push_back("1");
        q.push("1");
        while (true) {
            string f = q.front();
            q.pop();
            if (bin2Dec(f) >= t)
                break;

            string s1 = f + "0";
            string s2 = f + "1";

            q.push(s1);
            q.push(s2);

            ans.push_back(s1);
            ans.push_back(s2);
        }

        for (auto it: ans) {
            cout << it << " ";
        }

        cout << endl;
    }

    return 0;
}
