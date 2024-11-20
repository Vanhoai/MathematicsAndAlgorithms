#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
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

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;

        queue<string> q;
        vector<string> res;
        q.push("6");
        q.push("8");

        res.push_back("6");
        res.push_back("8");

        while (true) {
            string s = q.front();
            q.pop();
            if (s.size() > n - 1)
                break;

            string s1 = s + "6";
            string s2 = s + "8";

            res.push_back(s1);
            res.push_back(s2);

            q.push(s1);
            q.push(s2);
        }

        int size = res.size();
        for (int i = 0; i < size; i++) {
            cout << res[size - 1 - i] << " ";
        }

        cout << endl;
    }

    return 0;
}
