#include <algorithm>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

// Type Aliases
typedef long long ll;        // Alias for long long
typedef pair<int, int> pi;   // Alias for pair of integers
typedef vector<int> vi;      // Alias for vector of integers
typedef vector<ll> vll;      // Alias for vector of long long
typedef vector<pi> vii;      // Alias for vector of pairs
typedef vector<vi> vvi;      // Alias for vector of vectors
typedef vector<vector<double> > vvd;

// Macros for common operations
#define F  first       // Short for accessing first element of pair
#define S  second      // Short for accessing second element of pair
#define PB push_back   // Push back to vector
#define MP make_pair   // Make pair of two elements
#define ALL(v)                                                                 \
    (v).begin(), (v).end()   // Short for the whole range of a container

// Loop Macros
#define FOR(i, a, b) for (int i = a; i <= b; i++)   // Inclusive for loop [a, b]
#define FORD(i, a, b)                                                          \
    for (int i = a; i >= b; i--)   // For loop in descending order [a, b]
#define REP(i, n)    for (int i = 0; i < n; i++)   // Short loop from 0 to n-1
#define MEMSET(a, b) memset(a, b, sizeof(a))

// Constants
#define MOD  1000000007     // A large prime, used as modulo for calculations
#define INF  1e9            // Used as a large value (infinity) for graphs
#define EPS  1e-9           // Used as a small value for floating-point comparisons
#define MAXN 1001           // Common size limit for arrays

// Utility Macros
#define GCD(a, b) gcd(a, b)                 // Finds GCD of a and b
#define LCM(a, b) ((a) * (b) / GCD(a, b))   // Finds LCM of a and b
#define SQ(x) ((x) * (x))                   // Calculates square of x
#define SZ(x) ((int) (x).size())            // Returns size of container x
#define SORT(v) sort(ALL(v))                // Sorts a container in ascending order
#define MIN(a, l, r) min(a,l,r)             // Min of array       
#define MAX(a, l, r) max(a,l,r)             // Max of array
#define SORT_ASC(a, l, r) sort_asc(a, l, r) // Sort array in ascending order
#define SORT_DESC(a, l, r) sort_desc(a, l, r) // Sort array in descending order

// Fast I/O
#define FAST_IO                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr)

#define READ_WRITE_FILE read


// Shortening Cin and Cout (optional for reducing typing)
#define sc(x) cin >> x            // Shorter input command
#define pf(x) cout << x << endl   // Shorter output command with newline

// Functions
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void read() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

int min(int *a, int l, int r) {
    if (l == r) return a[l];
    if (l + 1 == r) {
        return a[l] > a[r] ? a[r] : a[l];
    }

    int m = (l + r) >> 1;
    int m1 = min(a, l, m);
    int m2 = min(a, m + 1, r);

    return m1 > m2 ? m2 : m1;
}

int max(int * a, int l, int r) {
    if (l == r) return a[l];
    if (l + 1 == r) {
        return a[l] < a[r] ? a[r] : a[l];
    }

    int m = (l + r) >> 1;
    int m1 = max(a, l, m);
    int m2 = max(a, m + 1, r);

    return m1 < m2 ? m2 : m1;
}

void sort_asc(int *a, int l, int r) {
    if (l >= r) return;
    int i = l, j = r, x = a[(l + r) >> 1];
    while (i <= j) {
        while (a[i] < x) i++;   
        while (a[j] > x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++, j--;
        }
    }

    sort_asc(a, l, j);
    sort_asc(a, i, r);
}

void sort_desc(int *a, int l, int r) {
    if (l >= r) return;   
    int i = l, j = r, x = a[(l + r) >> 1];
    while (i <= j) {
        while (a[i] > x) i++;   
        while (a[j] < x) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++, j--;
        }
    }

    sort_desc(a, l, j);
    sort_desc(a, i, r);
}
