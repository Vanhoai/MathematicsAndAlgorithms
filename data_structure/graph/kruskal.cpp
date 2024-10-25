#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int n, m;
int parent[1001];
int sz[1001];
vector<Edge> edges;

void makeSet() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find(parent[v]);
}

bool Union(int u, int v) {
    u = find(u);
    v = find(v);

    if (u == v)
        return false;

    if (sz[u] < sz[v])
        swap(u, v);

    parent[v] = u;
    sz[u] += sz[v];
    return true;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        Edge e = {x, y, w};
        edges.push_back(e);
    }
}

bool comparator(Edge a, Edge b) { return a.w < b.w; }

void kruskal() {
    vector<Edge> mst;
    int cost = 0;
    sort(edges.begin(), edges.end(), comparator);

    for (Edge e : edges) {
        if (Union(e.u, e.v)) {
            mst.push_back(e);
            cost += e.w;
        }
    }

    cout << "Cost: " << cost << " Size: " << mst.size() << endl;
    for (Edge e : mst) {
        cout << e.u << " " << e.v << endl;
    }
}

// 6 8
// 1 2 1
// 3 7 1
// 6 7 1
// 2 3 2
// 5 6 2
// 4 5 3
// 1 3 4
// 3 4 10

int main() {
    input();
    makeSet();
    kruskal();
    return 0;
}