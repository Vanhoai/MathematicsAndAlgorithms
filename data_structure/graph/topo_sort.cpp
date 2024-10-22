#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 7 7
// 1 2
// 2 3
// 2 4
// 2 7
// 3 6
// 4 5
// 7 6

int n, m;
vector<int> adj[1001];
int in_degree[1001];
vector<int> result;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    memset(in_degree, 0, sizeof(in_degree));
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int v : adj[i]) {
            in_degree[v]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);

        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    for (int u : result) {
        cout << u << " ";
    }

    cout << endl;
}

int main() {
    input();
    init();
    return 0;
}