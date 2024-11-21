#include <iostream>
using namespace std;

void READ_WRITE_FILE() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

const int N = 1e7 + 1;
int prime[N]; // 10^7 + 1

void init() {
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i < N; i++) {
        if (prime[i]) {
            for (int k = i * i; k < N; k += i) {
                prime[k] = 0;
            }
        }
    }
}

void solve(int n) {
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main_dev() {
    FAST_IO;
    READ_WRITE_FILE();

    int tc; cin >> tc;
    init()
    while (tc--) {
        int n; cin >> n;
        solve(n);
    }

    return 0;
}
























