#include "bits/stdc++.h"
using namespace std;

const int N = 1001;
int n, m, si, sj, ei, ej;
int a[N][N], d[N][N];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    cin >> si >> sj >> ei >> ej;
    memset(d, -1, sizeof(d));
}

int bfs() {
    queue<pair<int, int>> q;
    q.push({si, sj});
    
    d[si][sj] = 0;
    a[si][sj] = 0;
    while (!q.empty()) {
        pair<int, int> u = q.front(); q.pop();
        int i = u.first;
        int j = u.second;

        if (i == ei && j == ej)
            return d[i][j];

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == 1) {
                d[x][y] = d[i][j] + 1;
                q.push({x, y});
            }
        }
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC; cin >> TC;
    while (TC--) {
        input();
        cout << bfs() << endl;
    }

    return 0;
}