
#include "libraries.cpp"
using namespace std;

bool dfs(int u, int t, vvi& residualGraph, vector<int>& parent, vector<bool>& visited) {
    visited[u] = true;
    int n = residualGraph.size();
    if (u == t) return true;

    REP(v, n) {
        if (!visited[v] && residualGraph[u][v] > 0) {
            parent[v] = u;
            if (dfs(v, t, residualGraph, parent, visited)) {
                return true;
            }
        }
    }
    
    return false;
}

int fordFulkerson(vvi& graph, int s, int t) {
    int u, v;
    int n = graph.size();
    vvi residualGraph = graph;
    vector<int> parent(n);
    int maxFlow = 0;

    while (true) {
        vector<bool> visited(n, false);
        if (!dfs(s, t, residualGraph, parent, visited)) {
            break;
        }

        int pathFlow = INT_MAX;
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            pathFlow = min(pathFlow, residualGraph[u][v]);
        }

        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            residualGraph[u][v] -= pathFlow;
            residualGraph[v][u] += pathFlow;
        }

        maxFlow += pathFlow;
    }

    return maxFlow;
}

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();
    
    int n; cin >> n;
    vvi graph(n, vi(n));
    REP(i, n) {
        REP(k, n) cin >> graph[i][k];
    }

    int source = 0, sink = 5;
    cout << fordFulkerson(graph, source, sink) << endl;

    REP(k, n) {
        REP(b, n) {
            if (IS_PRIME(graph[k][b])) {
                cout << graph[k][b] << " ";
            }
        }
    }


    return 0;
}
