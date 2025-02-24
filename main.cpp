#include "bits/stdc++.h"
#include "bits/macros.h"
using namespace std;

const int maxn = 26;
int C[maxn][maxn];

void init() {
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            C[i][j] = (i + j) % maxn;
        }
    }
}

void solve(string k, string m) {
    string res = "";
    string rK = "";
    string rM = "";

    int i = 0, j = 0;
    while (j < m.size()) {
        char c = (char)(C[k[i] - 'A'][m[j] - 'A'] + 'A');
        
        cout << j + 1  << ". " << m[j] << " & " 
            << k[i] << " -> " << c << endl;
        
        rM += m[j];
        rK += k[i];

        res += c;

        j++;
        i++;
        if (i >= k.size()) i = 0;
    }

    cout << rM << endl;
    cout << rK << endl;
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    init();

    string k, m;
    getline(cin, k);
    getline(cin, m);

    stringstream ss1(k);
    stringstream ss2(m);

    string word;

    string key = "";
    string message = "";

    while (ss1 >> word) key += word;
    while (ss2 >> word) message += word;

    solve(key, message);
    return 0;
}