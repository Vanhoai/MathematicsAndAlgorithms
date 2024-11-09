#include <iostream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int n, m;
vector<Edge> edges;
int parent[1001];
int sized[1001];

// Disjoint Set Union Find

void make_set() {
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        sized[i] = 1;
    }
}

int find(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

bool Union(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a == b) return false;
    if (sized[a] < sized[b]) swap(a, b);
    
    parent[b] = a;
    sized[a] += sized[b];
    return true;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        Edge edge = {x, y, z};
        edges.push_back(edge);
    }
}

bool comparator(Edge a, Edge b) {
    return a.w < b.w;
}

void solve() {
    sort(edges.begin(), edges.end(), comparator);

    vector<Edge> mst;

    int size = edges.size();
    for (int i = 0; i < size; i++) {
        Edge e = edges[i];
        if (Union(e.u, e.v)) {
            mst.push_back(e);
        }
    }

    int length = mst.size();
    int cost = 0;
    for (int i = 0; i < length; i++) {
        cost += mst[i].w;
    }

    cout << "Cost: " << cost << " Size: " << mst.size() << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("./in.txt", "r", stdin);
        freopen("./out.txt", "w", stdout);
    #endif

    input();
    make_set();
    solve();

    return 0;
}
