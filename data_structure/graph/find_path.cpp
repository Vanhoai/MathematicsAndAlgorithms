#include <iostream>
#include <vector>
using namespace std;

#define MAX 1001

int n, m, st, en;
vector<int> adj[MAX];
bool visited[MAX];
int parent[MAX];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(visited, false, sizeof(visited));
    memset(parent, -1, sizeof(parent));
}

void dfs(int u) {
    visited[u] = true;
    for (int v: adj[u]) {
        if (!visited[v]) {
            parent[v] = u;
            dfs(v);
        }
    }
}

void solve() {
    input();
    cin >> st >> en;
    parent[st] = 0;
    dfs(st);

    vector<int> path;
    int cur = en;
    while (cur != st) {
        path.push_back(cur);
        cur = parent[cur];
    }

    path.push_back(cur);
    cout << path.size() << endl;
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main_graph() {
    solve();
    return 0;
}
