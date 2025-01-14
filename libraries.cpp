#include <iostream>
#include <vector>
using namespace std;

// Type Aliases
typedef long long ll;        // Alias for long long
typedef pair<int, int> pi;   // Alias for pair of integers
typedef vector<int> vi;      // Alias for vector of integers
typedef vector<ll> vll;      // Alias for vector of long long
typedef vector<pi> vii;      // Alias for vector of pairs
typedef vector<vi> vvi;      // Alias for vector of vectors
typedef vector<vector<double>> vvd;

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
#define MOD  1000000007   // A large prime, used as modulo for calculations
#define INF  1e9          // Used as a large value (infinity) for graphs
#define EPS  1e-9   // Used as a small value for floating-point comparisons
#define MAXN 1001   // Common size limit for arrays

// Utility Macros
#define GCD(a, b)   gcd(a, b)                 // Finds GCD of a and b
#define LCM(a, b)   ((a) * (b) / GCD(a, b))   // Finds LCM of a and b
#define SQ(x)       ((x) * (x))               // Calculates square of x
#define SZ(x)       ((int) (x).size())        // Returns size of container x
#define IS_PRIME(x) isPrime(x)                // Checks if x is prime

#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define IO  freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)

// Functions
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
