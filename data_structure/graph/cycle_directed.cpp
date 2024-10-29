#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
bool visited[1001];
bool processed[1001];

bool dfs(int u) {
    visited[u] = true;
    processed[u] = true;

    for (int v: adj[u]) {
        if (!visited[v]) {
            if (dfs(v)) {
                return true;
            }
        } else if (processed[v]) {
            return true;
        }
    }

    processed[u] = false;
    return false;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(visited, false, sizeof(visited));
    memset(processed, false, sizeof(processed));
}

// 6 6
// 1 2
// 1 3
// 3 4
// 4 6
// 6 5
// 5 3

bool sort() {
    int in_degree[1001];
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        for (int v: adj[i]) {
            in_degree[v]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while (!q.empty()) {
        int u = q.front();
        cout << "u: " << u << endl;
        q.pop();
        count++;
        for (int v: adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    return count != n;
}

int main_graph() {
    input();
    if (sort()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
