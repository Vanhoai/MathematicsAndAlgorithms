#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int u, v;
    int w;
};

int n, m;
vector<pair<int, int> > adj[1001];
bool used[1001];
int parent[1001], d[1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back(make_pair(y, z));
        adj[y].push_back(make_pair(x, z));
    }

    memset(used, false, sizeof(used));
    for (int i = 1; i <= n; i++) d[i] = INT_MAX;
}

void prime(int u) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
    vector<Edge> mst;
    int res = 0;
    q.push(make_pair(0, u));

    while (!q.empty()) {
        pair<int, int> top = q.top();
        q.pop();

        int x = top.second;
        int w = top.first;

        if (used[x]) continue;
        used[x] = true;
        res += w;
        if (u != x) {
            Edge e = {x, parent[x], w};
            mst.push_back(e);
        }

        const int size = adj[x].size();
        for (int i = 0; i < size; i++) {
            int y = adj[x][i].first;
            int z = adj[x][i].second;

            if (!used[y] && z < d[y]) {
                d[y] = z;
                parent[y] = x;
                q.push(make_pair(z, y));
            }
        }
    }

    cout << res << endl;
    for (int i = 0; i < mst.size(); i++) {
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
    prime(1);

    return 0;
}
