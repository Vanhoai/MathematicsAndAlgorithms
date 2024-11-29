//
// Created by Aurora Aurora on 21/11/24.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int &x : a)
        cin >> x;

    for (int i = 0; i < n; i++) {
        if (a[i] & 1) {
            cout << a[i] << " ";
        }
    }

    return 0;
}
