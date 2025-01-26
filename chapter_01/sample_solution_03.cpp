#include <iostream>
using namespace std;

// 6
// -2 11 -4 13 -5 2
// ans: 20

int maxLeft(int a[], int i, int j) {
    int maxSum = INT_MIN;
    int sum = 0;
    for (int k = j; k >= i; k--) {
        sum += a[k];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int maxRight(int a[], int i, int j) {
    int maxSum = INT_MIN;
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += a[k];
        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int maxSub(int a[], int i, int j) {
    if (i == j)
        return a[i];
    else {
        int m = (i + j) >> 1;
        int wL = maxSub(a, i, m);
        int wR = maxSub(a, m + 1, j);
        int wM = maxLeft(a, i, m) + maxRight(a, m + 1, j);

        return max(wL, wR, wM);
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;

    cout << maxSub(a, 0, n - 1) << endl;

    return 0;
}