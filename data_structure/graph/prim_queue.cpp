#include <cmath>
#include <climits>
#include <queue>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>   
#include <iostream>  
#include <sstream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <cassert>
using namespace std;

// Type Aliases
typedef long long ll;              // Alias for long long
typedef pair<int, int> pi;         // Alias for pair of integers
typedef vector<int> vi;             // Alias for vector of integers
typedef vector<ll> vll;             // Alias for vector of long long
typedef vector<pi> vii;             // Alias for vector of pairs

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

// Shortening Cin and Cout (optional for reducing typing)
#define sc(x) cin >> x              // Shorter input command
#define pf(x) cout << x << endl     // Shorter output command with newline

// Functions
int gcd(int a, int b) { if (b == 0) return a; return gcd(b, a % b); }


struct Edge {
    int u, v, w;
};

int n, m;
vii adj[1001];
bool used[1001];
int parent[1001], d[1001];

void input() {
    cin >> n >> m;
    REP(i, m) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].PB(MP(y, z));
        adj[y].PB(MP(x, z));
    }

    MEMSET(used, false);
    FOR(i, 1, n) d[i] = INT_MAX;
}

void prim(int u) {
    vector<Edge> MST;
    priority_queue<pi, vii, greater<pi> > Q;

    int res = 0;
    Q.push(MP(0, u));

    while (!Q.empty()) {
        pi top = Q.top(); Q.pop();
        int x = top.S;
        int wX = top.F;

        if (used[x]) continue;
        
        res += wX;
        used[x] = true;
        if (u != x) {
            Edge edge = {x, parent[x], wX};
            MST.PB(edge);
        }

        REP(i, adj[x].size()) {
            int y = adj[x][i].F;
            int w = adj[x][i].S;

            if (!used[y] && w < d[y]) {
                d[y] = w;
                parent[y] = x;
                Q.push(MP(w, y));
            }
        }
    }

    cout << "Res: " << res << endl;
    REP(i, MST.size()) {
        cout << MST[i].u << " " << MST[i].v << " " << MST[i].w << endl;
    }
}

int main() {
    FAST_IO;
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif

    input();
    prim(1);

    return 0;
}