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

int solve(int n, int t) {
    set<int> se;
    queue<pi> q;

    q.push(make_pair(n, 0));
    se.insert(n);

    while (!q.empty()) {
        pi f = q.front();
        q.pop();
        if (f.first == t)
            return f.second;
        if (f.first - 1 == t || f.first * 2 == t)
            return f.second + 1;

        if (se.find(f.first * 2) == se.end() && f.first < t) {
            q.push(make_pair(f.first * 2, f.second + 1));
            se.insert(f.first * 2);
        }

        if (se.find(f.first - 1) == se.end() && f.first > 1) {
            q.push(make_pair(f.first - 1, f.second + 1));
            se.insert(f.first - 1);
        }
    }

    return -1;
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc;
    cin >> tc;
    while (tc--) {
        int n, t;
        cin >> n >> t;
        cout << solve(n, t) << endl;
    }

    return 0;
}
