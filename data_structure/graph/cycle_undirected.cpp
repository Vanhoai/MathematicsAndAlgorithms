#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
}

bool dfs(int u, int p) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u)) {
                return true;
            } else if (v != p) {
                return true;
            }
        }
    }

    return false;
}

bool isCycle() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1))
                return true;
        }
    }

    return false;
}

int main_graph() {
    input();
    cout << isCycle() << endl;
    return 0;
}
