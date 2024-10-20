#include <iostream>
#include <queue>
using namespace std;

// 5 5
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
// 0 0 0 1 0

int n, m;
int a[1001][1001];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
}

void dfs(int i, int j) {
    a[i][j] = 0;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (a[x][y] == 1 && x >= 1 && x <= n && y >= 1 && y <= m) {
            dfs(x, y);
        }
    }
}

void bfs(int i, int j) {
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    a[i][j] = 0;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int x = front.first + dx[k];
            int y = front.second + dy[k];
            if (a[x][y] == 1 && x >= 1 && x <= n && y >= 1 && y <= m) {
                a[x][y] = 0;
                q.push(make_pair(x, y));
            }
        }
    }
}

int countConnected() {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                count++;
                bfs(i, j);
            }
        }
    }
    return count;
}

int main() {
    input();
    cout << "Connected components: " << countConnected() << endl;
    return 0;
}