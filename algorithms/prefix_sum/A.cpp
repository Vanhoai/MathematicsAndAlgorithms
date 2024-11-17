#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;
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


int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int n; cin >> n;
    int a[n], prefix[n];
    REP(i, 0, n - 1) cin >> a[i];

    memset(prefix, 0, sizeof(prefix));
    prefix[0] = a[0];
    REP(i, 1, n - 1) prefix[i] = prefix[i - 1] + a[i];

    int q; cin >> q;
    while (q--) {
        int L, R; cin >> L >> R;
        cout << prefix[R] - prefix[L - 1] << endl;
    }

    return 0;
}
























