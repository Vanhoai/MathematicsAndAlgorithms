#include <iostream>
#include <iomanip>
#include <map>
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

    int n, k; cin >> n >> k;
    int a[n]; for (int &x: a) cin >> x;

    int prefix[n + 1];
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) prefix[i] = prefix[i - 1] + a[i];

    for (int x: a) {
        cout << x << " ";
    }

    return 0;
}
























