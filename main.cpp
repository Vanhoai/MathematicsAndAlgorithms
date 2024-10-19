#include "data_structure/tree/segment_tree.cpp"
#include <iostream>
#include <vector>
using namespace std;

#define max 1001

int a[max], segTree[4 * max];

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

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    buildTree(1, 0, n - 1);

    for (int i = 1; i < 2 * n; i++) {
        cout << segTree[i] << " ";
    }

    return 0;
}
