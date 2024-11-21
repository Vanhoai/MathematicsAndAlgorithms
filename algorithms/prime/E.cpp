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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int euler(LL n) {
    int res = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            res -= res / i;
        }
    }

    if (n != 1) {
        res -= res / n;
    }

    return res;
}

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();

    int TC; cin >> TC;
    while (TC--) {
        int n; cin >> n;
        cout << euler(n) << endl;
    }
 
    return 0;
}
























