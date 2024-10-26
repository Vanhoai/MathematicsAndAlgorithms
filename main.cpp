
#include "libraries.cpp"
using namespace std;

const int N = 1001;
int n, m;
vi adj[N];
bool visited[N];

void input() {
    cin >> n >> m;
    REP(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    MEMSET(visited, false);
}

void dfs(int u) {
    visited[u] = true;
    REP(i, SZ(adj[u])) {
        if (!visited[adj[u][i]]) {
            dfs(adj[u][i]);
        }
    }
}

void solve() {
    int connected = 0;
    FOR(i, 1, n) {
        if (!visited[i]) {
            connected++;
            dfs(i);
        }
    }

    MEMSET(visited, false);

    int ans = 0;
    vi res;

    FOR(i, 1, n) {
        int count = 0;
        visited[i] = true;
        FOR(k, 1, n) {
            if (!visited[k]) {
                count++;
                dfs(k);
            }
        }

        if (count > connected) {
            ans += 1;
            res.PB(i);
        }

        MEMSET(visited, false);
    }

    cout << "Ans: " << ans << endl;
    REP(i, SZ(res)) { cout << res[i] << " "; }
}

int main() {
    FAST_IO;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    input();
    solve();

    return 0;
}