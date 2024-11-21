//
// Created by Aurora ICP on 21/11/24.
//

#include <iostream>
#include <thread>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define READ_WRITE_FILE freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout)

int main() {
    FAST_IO;
    READ_WRITE_FILE;

    int TC;
    cin >> TC;
    while (TC--) {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int &x: a) cin >> x;

        int i = -1;
        int count = 0;
        int size = n;
        while (size > 1) {
            if (i == size - 1) {
                i = 0;
            } else {
                i++;
            }

            count++;
            if (count == k) {
                for (int j = i; j < size - 1; j++) {
                    a[j] = a[j + 1];
                }

                size--;
                count = 1;
                if (i == size) i = 0;
            }
        }

        cout << a[0] << endl;
    }

    return 0;
}
