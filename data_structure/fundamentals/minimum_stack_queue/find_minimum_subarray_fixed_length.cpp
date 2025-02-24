#include "bits/stdc++.h"
using namespace std;

/**
 * Find minimum/maximum element in subarray fixed length k
 * with this problem we can approach with minimum queue
 * -> we can use 3 way implement minimum queue for solve this problem
 *
 * input:
 *      T, N, K, A[i]
 *      1 <= T <= 1000
 *      1 <= N, K <= 10^6
 *      1 <= A[i] <= 10^6
 *
 * output: print the min/max element in subarray length k
 *
 * @example
 * input:
 *      1
 *      10 3
 *      3 2 1 8 9 7 6 5 4 10
 *
 * output:
 *      min: 1 1 1 7 6 5 4 4
 *      max: 3 8 9 9 9 7 6 10
 */
void solve_min(int a[], int n, int k) {
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        // Remove elements greater than current element from back
        while (!dq.empty() && a[dq.back()] > a[i])
            dq.pop_back();

        dq.push_back(i);
    }

    // Process rest of the elements
    for (int i = k; i < n; i++) {
        // Add minimum element from current window to result
        cout << a[dq.front()] << " ";
        
        // Remove elements outside current window
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        
        // Remove elements greater than current element
        while (!dq.empty() && a[dq.back()] > a[i])
            dq.pop_back();
        
        dq.push_back(i);
    }

    cout << a[dq.front()];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k; cin >> n >> k;

        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        solve_min(a, n, k);
    }

    return 0;
}