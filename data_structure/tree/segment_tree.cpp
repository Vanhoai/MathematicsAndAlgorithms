#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
private:
    vector<int> tree;
    int size;

    void buildTree(vector<int> &arr, const int node, const int start, const int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            const int mid = (start + end) / 2;
            buildTree(arr, 2 * node, start, mid);
            buildTree(arr, 2 * node + 1, mid + 1, end);

            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

public:
    SegmentTree(vector<int> &arr) {
        size = arr.size();
        tree.resize(4 * size);   // Size tree will be 4*n
        buildTree(arr, 1, 0, size - 1);
    }

    void printTree() {
        for (int i = 1; i < 2 * size; i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }
};

// int main() {
//     vector<int> arr = {1, 3, 5, 7, 9, 11};
//     SegmentTree st(arr);
//     st.printTree();
//     return 0;
// }