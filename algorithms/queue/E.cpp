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
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<pi> vii;

#define FAST_IO                     \
    ios::sync_with_stdio(false);    \
    cin.tie(nullptr);               \
    cout.tie(nullptr)

#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = (a); i <= (b); i++)

void READ_WRITE_FILE() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

const int MAXN = 1001;
int n, m;
int stx, sty, edx, edy;
int a[MAXN][MAXN];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct Node {
    int x;
    int y;
    int step;
};

void input() {
    memset(a, 0, sizeof(a));
    cin >> n >> m >> stx >> sty >> edx >> edy;
    REP(i, 1, n) REP(k, 1, m) cin >> a[i][k];
}

int solve() {
    queue<Node> q;
    q.push({stx, sty, 0});

    int step = -1;

    while(!q.empty()) {
        Node t = q.front();
        q.pop();

        REP(i, 0, 3) {
            int i1 = t.x + dx[i];
            int j1 = t.y + dy[i];

            if (i1 == edx && j1 == edy) {
                return t.step + 1;
            }

            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 1) {
                a[i1][j1] = 0;
                q.push({i1, j1, t.step + 1});
            }
        }
    }

    return -1;
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc; cin >> tc;
    while (tc--) {
        input();
        cout << solve() << endl;
    }

    return 0;
}
























