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

// 1. using deque<int>

/**
 * 1. using deque with add the end and remove from front
 *
 *
 * deque<int> q;
 * 1. Finding the minimum
 * int minimum = q.front();
 *
 * 2. Add an element
 * while (!q.empty() && q.back() > new_element)
 * 		q.pop_back();
 *
 * q.push_back(new_element);
 *
 * 3. Remove an element
 * if (!q.empty() && q.front() == remove_element)
 * 		q.pop_front();
 */
void solve_min(int a[], int n, int k) {
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && q.back() > a[i])
            q.pop_back();

        q.push_back(a[i]);
    }

    cout << q.front() << " ";
    for (int i = 1; i < n - k + 1; i++) {
        cout << a[i] << " ";
    }   

    cout << endl;
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