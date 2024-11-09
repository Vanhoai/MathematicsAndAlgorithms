#include <iostream>
#include <map>
#include <bitset>
using namespace std;

#define FAST_IO                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(nullptr);                                                          \
    cout.tie(nullptr)

void READ_WRITE_FILE() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
}

int main() {
    FAST_IO;
    READ_WRITE_FILE();

    int n = 10;

    int b = ~n;

    cout << bitset<8>(n) << endl;
    cout << bitset<8>(b) << endl;

    return 0;
}