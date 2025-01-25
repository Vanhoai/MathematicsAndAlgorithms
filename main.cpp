#include "./data_abstraction/template/Template.h"
#include "./libraries.cpp"
using namespace std;

int main() {
    IOS;
    IO;

    Bag<int> A;
    Bag<char> B;

    for (int i = 92; i <= 122; i++) {
        A.insert(i);
        B.insert(i);
    }

    cout << A << endl;
    cout << B << endl;

    return 0;
}
