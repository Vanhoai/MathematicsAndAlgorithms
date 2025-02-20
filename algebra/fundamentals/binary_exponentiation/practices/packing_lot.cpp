#include "bits/stdc++.h"
using namespace std;

/**
 * Codeforce: https://codeforces.com/problemset/problem/630/I
 * 
 * To quickly hire highly skilled specialists one of the new IT City companies 
 * made an unprecedented move. Every employee was granted a car, and an employee
 * can choose one of four different car makes.
 * The parking lot before the office consists of one line of (2n-2) parking 
 * spaces. Unfortunately the total number of cars is greater than the parking 
 * lot capacity. Furthermore even amount of cars of each make is greater than 
 * the amount of parking spaces! That's why there are no free spaces on the 
 * parking lot ever.
 * Looking on the straight line of cars the company CEO thought that parking 
 * lot would be more beautiful if it contained exactly n successive cars of 
 * the same make. Help the CEO determine the number of ways to fill the parking 
 * lot this way. 
 * 
 * Input
 * The only line of the input contains one integer n (3≤n≤30) — the amount of 
 * successive cars of the same make.
 * Output
 * Output one integer — the number of ways to fill the parking lot by cars 
 * of four makes using the described way.
 * 
 * Note
 * Let's denote car makes in the following way: A — Aston Martin, B — Bentley, 
 * M — Mercedes-Maybach, Z — Zaporozhets. For n=3 there are the following 
 * appropriate ways to fill the parking lot: AAAB AAAM AAAZ ABBB AMMM AZZZ BBBA 
 * BBBM BBBZ BAAA BMMM BZZZ MMMA MMMB MMMZ MAAA MBBB MZZZ ZZZA ZZZB ZZZM ZAAA ZBBB ZMMM
 * Originally it was planned to grant sport cars of Ferrari, Lamborghini, 
 * Maserati and Bugatti makes but this idea was renounced because it is 
 * impossible to drive these cars having small road clearance on the worn-down 
 * roads of IT City.
 * 
 * @example
 * input: 
 * 3
 * 
 * output:
 * 24
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    return 0;
}
