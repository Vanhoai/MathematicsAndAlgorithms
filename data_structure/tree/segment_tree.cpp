#include <iostream>
using namespace std;

#define MAX 1001

int a[MAX], segTree[4 * MAX];

void buildTree(int node, int start, int end) {
    if (start == end) {
        segTree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        buildTree(2 * node, start, mid);
        buildTree(2 * node + 1, mid + 1, end);

        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

void update(int node, int start, int end, int index, int value) {
    if (start == end) {
        segTree[node] = value;
    } else {
        const int mid = (start + end) / 2;
        if (index <= mid) {
            update(2 * node, start, mid, index, value);
        } else {
            update(2 * node + 1, mid + 1, end, index, value);
        }

        segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
    }
}

int query(int node, int start, int end, int left, int right) {
    if (left > right)
        return 0;

    if (start == left && end == right)
        return segTree[node];
    else {
        const int mid = (start + end) / 2;
        int s1 = query(2 * node, start, mid, left, min(mid, right));
        int s2 = query(2 * node + 1, mid + 1, end, max(mid + 1, left), right);
        return s1 + s2;
    }
}

// 8
// 1 2 3 4 5 6 7 8

// input: n = 8
// a = { 1, 2, 3, 4, 5, 6, 7, 8 }
// => segment tree: 36 10 26 3 7 11 15 1 2 3 4 5 6 7 8
// a = { 1, 2, 3, 4, 8, 6, 7, 8 }

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    buildTree(1, 0, n - 1);
    update(1, 0, n - 1, 4, 8);

    const int sum = query(1, 0, n - 1, 5, 7);
    cout << sum << endl;

    return 0;
}
