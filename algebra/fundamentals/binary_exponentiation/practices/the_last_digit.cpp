#include "bits/stdc++.h"
using namespace std;

/**
 * SPOJ: https://www.spoj.com/problems/LASTDIG/
 * 
 * Nestor was doing the work of his math class about three days but he is tired
 * of make operations a lot and he should deliver his task tomorrow. His math’s 
 * teacher gives him two numbers a and b. The problem consist of finding the 
 * last digit of the potency of base a and index b. Help Nestor with his problem. 
 * You are given two integer numbers: the base a (0 <= a <= 20) and the index 
 * b (0 <= b <= 2,147,483,000), a and b both are not 0. You have to find the 
 * last digit of ab.
 * 
 * Input
 * The first line of input contains an integer t, the number of test cases 
 * (t <= 30). t test cases follow. For each test case will appear a and b 
 * separated by space.
 * 
 * Output
 * For each test case output an integer per line representing the result.
 * 
 * @example
 * input:
 * 2
 * 3 10
 * 6 2
 * 
 * output:
 * 9
 * 6
 * 
*/


int solve(int a, int b) {
    if (b == 0) return 1;
    int res = solve(a, b / 2);
    res *= res;
    if(b & 1) res *= a;
    
    return res % 10;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T; cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }

    return 0;
}
