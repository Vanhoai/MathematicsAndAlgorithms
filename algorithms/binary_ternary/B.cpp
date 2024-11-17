#include <iostream>
#include <iomanip>
using namespace std;

typedef long long LL;
typedef pair<int, int> pi;
typedef vector<pi> vii;

#define FAST_IO                     \
    ios::sync_with_stdio(false);    \
    cin.tie(nullptr);               \
    cout.tie(nullptr)

#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = (a); i <= (b); i++)

void READ_WRITE_FILE() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

// fx = ax^2 + bx + c
// => x (fx max [L, R])

double a, b, c;
double L, R;
double epsilon = 1e-6;

double f(double x) {
    return a * x * x + b * x + c;
}

double ternary_search() {
    while (R - L > epsilon) {
        double m1 = L + (R - L) / 3;
        double m2 = R - (R - L) / 3;

        if (f(m1) < f(m2)) {
            L = m1;
        } else {
            R = m2;
        }
    }

    return (L + R) / 2;
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    cin >> a >> b >> c >> L >> R;
    double ans = ternary_search();
    cout << fixed << setprecision(6) << "x = " << ans << " f(x) = " << f(ans) << endl;
 
    return 0;
}
























