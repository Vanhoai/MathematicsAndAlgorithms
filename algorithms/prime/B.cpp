#include <iostream>
using namespace std;

typedef pair<int, int> pi;
typedef vector<pi> vii;

#define FAST_IO                     \
    ios::sync_with_stdio(false);    \
    cin.tie(nullptr);               \
    cout.tie(nullptr)

#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = (a); i <= (b); i++)

void READ_WRITE_FILE() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}


typedef long long ll;

long long max(long long a, long long b) {
    return a > b ? a : b;
}

void solve(long long L, long long  R) {
    int prime[R - L + 1];
    memset(prime, 1, sizeof(prime));

    for (long long i = 2; i * i <= R; i++) {
        long long s = max(i * i, (L + i - 1) / i * i);
        for (long long k = s; k <= R; k += i) {
            prime[k - L] = 0;
        }
    }

    for (long long i = L; i <= R; i++) {
        if (prime[i - L]) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc; cin >> tc;
    while (tc--) {
        long long L, R; cin >> L >> R;
        solve(L, R);
    }

    return 0;
}
























