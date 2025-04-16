#include <iostream>
using namespace std;

/**
 * Queue Modification for find min element in O(1) time
 * 3 way to do this:
 * 1. using deque with add the end and remove from front
 * 2. same method 1 but save index with deque<pair<int, int>>
 * 3. using 2 stack
 */

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

int find_min_method_1(int a[], int n) {
    deque<int> q;
    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.back() > a[i])
            q.pop_back();

        q.push_back(a[i]);
    }

    return q.front();
}

/**
 * 2. same method 1 but save index with deque<pair<int, int>>
 * is this way we can see count added and count removed
 * which help us follow the number of element added and removed
 * for used in query minimum in range k element
 *
 * deque<pair<int, int>> q;
 * int cnt_added = 0;
 * int cnt_removed = 0;
 *
 * 1. Finding the minimum
 * int minimum = q.front();
 *
 * 2. Add an element
 * while (!q.empty() && q.back().first > new_element)
 * 		q.pop_back();
 *
 * q.push_back({new_element, cnt_added});
 * cnt_added++;
 *
 * 3. Remove an element
 * if (!q.empty() && q.front().second == cnt_removed)
 * 		q.pop_front();
 *
 * cnt_removed++;
 */

int find_min_method_2(int a[], int n) {
    deque<pair<int, int>> q;
    int cnt_added = 0;
    int cnt_removed = 0;

    for (int i = 0; i < n; i++) {
        while (!q.empty() && q.back().first > a[i])
            q.pop_back();

        q.push_back({a[i], cnt_added});
        cnt_added++;
    }

    return q.front().first;
}

/**
 * 3. using 2 stack to find min element in O(1) time
 *
 * stack<pair<int, int>> s1, s2;
 * 1. Finding the minimum
 * if (s1.empty() || s2.empty())
 *       minimum = s1.empty() ? s2.top().second : s1.top().second;
 * else
 *      minimum = min(s1.top().second, s2.top().second);
 *
 * 2. Add an element
 * int minimum = s1.empty() ? new_element : min(new_element, s1.top().second);
 * s1.push({new_element, minimum});
 *
 * 3. Remove an element
 * if (s2.empty()) {
 *      while (!s1.empty()) {
 *          int element = s1.top().first;
 *          s1.pop();
 *          int minimum = s2.empty() ? element : min(element, s2.top().second);
 *          s2.push({element, minimum});
 *      }
 * }
 *
 * int remove_element = s2.top().first;
 * s2.pop();
 */

int find_min_method_3(int a[], int n) {
    stack<pair<int, int>> s1, s2;
    for (int i = 0; i < n; i++) {
        int minimum = s1.empty() ? a[i] : min(a[i], s1.top().second);
        s1.push({a[i], minimum});
    }

    while (!s1.empty()) {
        int element = s1.top().first;
        s1.pop();
        int minimum = s2.empty() ? element : min(element, s2.top().second);
        s2.push({element, minimum});
    }

    return s2.top().second;
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

    cout << find_min_method_1(a, n) << endl;
    cout << find_min_method_2(a, n) << endl;
    cout << find_min_method_3(a, n) << endl;

    return 0;
}
