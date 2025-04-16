#include <iostream>
using namespace std;

/**
 * Implement find an min element with stack
 * stack<pair<int, int>> st;
 *
 * 1. Adding an element
 * int new_min = st.empty() ? new_elem : min(new_elem, st.top().second);
 * st.push({new_elem, new_min});
 *
 * 2. Removing an element:
 * int removed_element = st.top().first;
 * st.pop();
 *
 * 3. Finding the minimum:
 * int minimum = st.top().second;
 */

int find_min(int a[], int n) {
    stack<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        int new_min = st.empty() ? a[i] : min(a[i], st.top().second);
        st.push({a[i], new_min});
    }

    return st.top().second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << find_min(a, n) << endl;
    return 0;
}
