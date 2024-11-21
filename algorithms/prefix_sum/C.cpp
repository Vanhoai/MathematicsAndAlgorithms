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
#define LOOP(i, b) for (int i = 0; i < (b); i++)

void READ_WRITE_FILE() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();

    int n, m;
    cin >> n >> m;
    int a[n][m];
    LOOP(i, n)
        LOOP(j, m) cin >> a[i][j];

    return 0;
}
























