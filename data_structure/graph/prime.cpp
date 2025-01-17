#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int n, m;
vector<pair<int, int>> adj[1001];
bool used[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }

    memset(used, false, sizeof(used));
}

void prim(int u) {
    vector<Edge> mst;
    int d = 0;

    used[u] = true;   // mark u true -> move u from v to mst
    while (mst.size() < n - 1) {
        int min_w = INT_MAX;
        int x, y;

        for (int i = 1; i <= n; i++) {
            if (used[i]) {   // if i is in mst
                const int size = adj[i].size();
                for (int k = 0; k < size; k++) {
                    pair<int, int> v = adj[i][k];
                    int j = v.first;
                    int w = v.second;

                    if (!used[j] && w < min_w) {
                        min_w = w;
                        x = j;
                        y = i;
                    }
                }
            }
        }

        Edge e = {x, y, min_w};
        mst.push_back(e);
        d += min_w;
        used[u] = true;
    }

    cout << d << endl;
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