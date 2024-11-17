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

const int N = 1e7 + 1;
int prime[N];

void init() {
    REP(i, 0, N) prime[i] = i;

    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (prime[i] == i) {
            for (int k = i * i; k <= N; k += i) {
                if (prime[k] == k) {
                    prime[k] = i;
                }
            }
        }
    }
}

void solve(int n, int *a) {
    REP(i, 0, n - 1) {
        cout << a[i] << " = ";
        while (a[i] != 1) {
            cout << prime[a[i]] << " ";
            a[i] /= prime[a[i]];
        }

        cout << endl;
    }
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    init();
    int n; cin >> n;
    int a[n]; REP(i, 0, n - 1) cin >> a[i];
    solve(n, a);

    return 0;
}
























