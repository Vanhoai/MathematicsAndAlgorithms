#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define IO  freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

// G(V, E)
template <typename T, typename W> class Graph {
private:
    vector<vector<pair<T, W>>> adj;
    int V;
    int E;

public:
    Graph() {
        V = 0, E = 0;
        adj.clear();
    }

    Graph(vector<tuple<T, T, W>> &edges) {
        V = 0, E = 0;
        adj.clear();
        for (auto &edge : edges) {
            V = max(V, get<0>(edge) + 1);
            V = max(V, get<1>(edge) + 1);
            E++;
        }
        adj.resize(V);
        for (auto &edge : edges) {
            int u = get<0>(edge), v = get<1>(edge);
            adj[u].push_back({v, get<2>(edge)});
            adj[v].push_back({u, get<2>(edge)});
        }
    }
};

int main() {
    IOS;
    IO;

    return 0;
}
