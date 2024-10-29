#include <queue>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

// Type Aliases
typedef long long ll; // Alias for long long
typedef pair<int, int> pi; // Alias for pair of integers
typedef vector<int> vi; // Alias for vector of integers
typedef vector<ll> vll; // Alias for vector of long long
typedef vector<pi> vii; // Alias for vector of pairs

// Macros for common operations
#define F first                     // Short for accessing first element of pair
#define S second                    // Short for accessing second element of pair
#define PB push_back                // Push back to vector
#define MP make_pair                // Make pair of two elements
#define ALL(v) (v).begin(), (v).end() // Short for the whole range of a container

// Loop Macros
#define FOR(i, a, b) for (int i = a; i <= b; i++)       // Inclusive for loop [a, b]
#define FORD(i, a, b) for (int i = a; i >= b; i--)      // For loop in descending order [a, b]
#define REP(i, n) for (int i = 0; i < n; i++)           // Short loop from 0 to n-1
#define MEMSET(a, b) memset(a, b, sizeof(a))

// Constants
#define MOD 1000000007              // A large prime, used as modulo for calculations
#define INF 1e9                     // Used as a large value (infinity) for graphs
#define EPS 1e-9                    // Used as a small value for floating-point comparisons
#define MAXN 1001                   // Common size limit for arrays

// Utility Macros
#define GCD(a, b) gcd(a, b)       // Finds GCD of a and b
#define LCM(a, b) ((a) * (b) / GCD(a, b)) // Finds LCM of a and b
#define SQ(x) ((x) * (x))           // Calculates square of x
#define SZ(x) ((int)(x).size())     // Returns size of container x
#define SORT(v) sort(ALL(v))        // Sorts a container in ascending order

// Fast I/O
#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

// Functions
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}


const int N = 1001;
int n, m;
vi adj[N];
int color[N]; // 0 = red, 1 = blue

void input() {
    cin >> n >> m;
    REP(i, m) {
        int x, y;
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }

    MEMSET(color, -1);
}

bool bfs(int u) {
    queue<int> Q;
    Q.push(u);
    color[u] = 0;
    while (!Q.empty()) {
        int x = Q.front();
        Q.pop();
        REP(i, adj[x].size()) {
            int v = adj[x][i];
            if (color[v] == -1) {
                color[v] = 1 - color[x];
                Q.push(v);
            } else if (color[v] == color[x]) {
                return false;
            }
        }
    }

    return true;
}

bool dfs(int u, int p) {
    color[u] = 1 - color[p];
    REP(i, adj[i].size()) {
        int v = adj[u][i];
        if (color[v] == -1) {
            if (!dfs(v, u))
                return false;
        } else if (color[v] == color[u]) {
            return false;
        }
    }

    return true;
}

int main_graph() {
    FAST_IO;

    input();
    bool check = true;
    FOR(i, 1, n) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                check = false;
                break;
            }
        }
    }

    if (check) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
