#include <iostream>
using namespace std;

int m;
int a[1001];
int p[1001 * 4];

// segment tree with node is max
void build_tree(int n, int l, int r) {
    if (l == r) {
        p[n] = a[l];
    } else {
        int m = (l + r) >> 1;
        build_tree(n * 2, l, m);
        build_tree(n * 2 + 1, m + 1, r);
        p[n] = max(p[2 * n], p[2 * n + 1]);
    }
}

void update(int n, int l, int r, int pos, int value) {
    if (l == r) {
        p[n] = value;
    } else {
        int m = (l + r) >> 1;
        if (pos <= m) {
            update(n * 2, l, m, pos, value);
        } else {
            update(n * 2 + 1, m + 1, r, pos, value);
        }

        p[n] = max(p[2 * n], p[2 * n + 1]);
    }
}

int query(int n, int l, int r, int u, int v) {
    if (u > r || v < l) return 0;
    if (u <= l && v >= r) return p[n];
    int m = (l + r) >> 1;
    return max(query(n * 2, l, m, u, v), query(n * 2 + 1, m + 1, r, u, v));
}

void solve() {
    cin >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    build_tree(1, 0, m - 1);
    
    for (int i = 1; i <= m * 2; i++) {
        cout << p[i] << " ";
    }

    // int q; cin >> q;
    // while (q--) {
    //     int x, y; cin >> x >> y;
    //     cout << query(1, 0, n - 1, x, y) << endl;
    // }
}

int main() {
    solve();
    return 0;
}