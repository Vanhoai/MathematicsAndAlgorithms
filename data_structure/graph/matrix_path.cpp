#include <iostream>
#include <queue>
using namespace std;

// 4 4 4 3
// o o o x
// x o x o
// o o x x
// o o A x

int n, m, x, y;
char a[1001][1001];
int step[1001][1001];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void input() {
    cin >> n >> m >> x >> y;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    memset(step, 0, sizeof(step));
}

bool dfs(int i, int j) {
    if (a[i][j] == 'A')
        return true;
    a[i][j] = 'x';
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (a[x][y] != 'x' && x >= 1 && x <= n && y >= 1 && y <= m) {
            if (dfs(x, y))
                return true;
        }
    }

    return false;
}

void bfs(const int i, const int j) {
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    a[i][j] = 'x';
    step[i][j] = 0;
    while (!q.empty()) {
        pair<int, int> front = q.front();
        const int i = front.first;
        const int j = front.second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int i1 = i + dx[k];
            int j1 = j + dy[k];
            if (a[i1][j1] != 'x' && i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m) {
                step[i1][j1] = step[i][j] + 1;
                if (a[i1][j1] == 'A')
                    return;
                a[i1][j1] = 'x';
                q.push(make_pair(i1, j1));
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
    bfs(1, 1);

    if (step[x][y] == 0) {
        cout << "No path" << endl;
    } else {
        cout << step[x][y] << endl;
    }

    return 0;
}