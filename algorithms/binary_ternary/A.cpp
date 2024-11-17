#include <iostream>
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

bool search(int *a, int n, int x) {
    int L = 0;
    int R = n - 1;

    while (L <= R) {
        int m = (L + R) >> 1;
        if (a[m] == x) return true;
        if (a[m] < x) L = m + 1;
        else R = m - 1;
    }

    return false;
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();
    
    int TC, n;
    int a[n];
    cin >> TC >> n;
    REP(i, 0, n - 1) cin >> a[i];

    while (TC--) {
        int x; cin >> x;
        if (search(a, n, x)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
 
    return 0;
}
























