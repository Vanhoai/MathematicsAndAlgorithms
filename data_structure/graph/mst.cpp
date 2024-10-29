#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vii;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define maxn 1001


struct Edge {
    int u, v, w;
};

int n, m;
bool used[maxn];
vii adj[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].PB(MP(y, z));
        adj[y].PB(MP(x, z));
    }

    memset(used, false, sizeof(used));
}

void prim(int u) {
    vector<Edge> mst;
    int d = 0;
    used[u] = true;

    while (mst.size() < n - 1) {
        int min_w = INT_MAX;
        int x, y;

        for (int i = 1; i <= n; i++) {
            if (used[i]) {
                const int size = adj[i].size();
                for (int k = 0; k < size; k++) {
                    pair<int, int> v = adj[i][k];
                    int j = v.F;
                    int w = v.S;

                    if (!used[j] && w < min_w) {
                        min_w = w;
                        x = i;
                        y = j;
                    }
                }
            }
        }

        Edge e = {x, y, min_w};
        used[y] = true;
        d += min_w;
        mst.push_back(e);
    }

    cout << "d: " << d << endl;
    const int size = mst.size();
    for (int i = 0; i < size; i++) {
        cout << mst[i].u << " " << mst[i].v << " " << mst[i].w << endl;
    }
}

int main_graph() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    input();
    prim(1);

    return 0;
}
