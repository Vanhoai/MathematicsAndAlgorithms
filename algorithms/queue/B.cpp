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

int bin2Dec(string s) {
    int sum = 0;
    int size = s.size();
    for (int i = 0; i < size; i++) {
        int bit = s[size - i - 1] - '0';
        sum += bit * (1 << i);
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
        q.push("9");

        int res = 0;
        while (true) {
            string f = q.front();
            q.pop();
            if (stoi(f) % t == 0) {
                res = stoi(f);
                break;
            }

            string s1 = f + "0";
            string s2 = f + "9";

            q.push(s1);
            q.push(s2);
        }

        cout << res << endl;
    }

    return 0;
}
