#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int n, m;
vector<int> adj[1001];
vector<int> reverse_adj[1001];
stack<int> st;
bool visited[1001];
vector<string> result;
string ans;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        reverse_adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
}

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }

    st.push(u);
}

void dfs_solve(int u) {
    visited[u] = true;
    ans += to_string(u) + " ";
    for (int v : reverse_adj[u]) {
        if (!visited[v]) {
            dfs_solve(v);
        }
    }
}

void strong_connected_component() {
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }

    memset(visited, false, sizeof(visited));

    while (!st.empty()) {
        int u = st.top();
        st.pop();

        if (!visited[u]) {
            ans += to_string(u) + " ";
            visited[u] = true;
            for (int v : reverse_adj[u]) {
                if (!visited[v]) {
                    dfs_solve(v);
                }
            }

            result.push_back(ans);
            ans = "";
        }
    }
}

// 7 8
// 1 2
// 2 3
// 3 1
// 3 4
// 4 5
// 5 6
// 6 7
// 7 5

int main() {
    input();
    strong_connected_component();

    for (int i = 0; i < result.size(); i++) {
        cout << "SCC " << i + 1 << ": " << result[i] << endl;
    }

    return 0;
}