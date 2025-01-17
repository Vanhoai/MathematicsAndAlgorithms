#include <iostream>
#include <map>
using namespace std;

#define F  first       // Short for accessing first element of pair
#define S  second      // Short for accessing second element of pair
#define PB push_back   // Push back to vector
#define MP make_pair   // Make pair of two elementsx

#define FAST_IO                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr)

#define READ_WRITE_FILE read

void read() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}

const int MAXN = 1001;
int a[MAXN];
int T[MAXN << 2];

void build(int n, int L, int R) {
    if (L == R) {
        T[n] = a[L];
    } else {
        int m = (L + R) >> 1;
        build(n << 1, L, m);
        build(n << 1 | 1, m + 1, R);
        T[n] = T[n << 1] + T[n << 1 | 1];
    }
}

void update(int n, int L, int R, int i, int v) {
    if (L == R) {
        T[n] = v;
    } else {
        int m = (L + R) >> 1;
        if (i <= m) {
            update(n << 1, L, m, i, v);
        } else {
            update(n << 1 | 1, m + 1, R, i, v);
        }
        T[n] = T[n << 1] + T[n << 1 | 1];
    }
}

int query(int n, int L, int R, int i, int j) {
    if (L == i && R == j) {
        return T[n];
    }

    int m = (L + R) >> 1;
    if (j <= m) {
        return query(n << 1, L, m, i, j);
    } else if (i > m) {
        return query(n << 1 | 1, m + 1, R, i, j);
    } else {
        return query(n << 1, L, m, i, m) +
               query(n << 1 | 1, m + 1, R, m + 1, j);
    }
}

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}