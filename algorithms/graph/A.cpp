#include <iostream>
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

int n, m;
vector<int> adj[1001];
bool visited[1001];

void dfs(int u) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (visited[v]) {
            dfs(v);
        }
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    memset(visited, false, sizeof(visited));
}

void solve() {
    input();
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            count++;
        }
    }

    cout << count << endl;
}

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();
    solve();
    return 0;
}
