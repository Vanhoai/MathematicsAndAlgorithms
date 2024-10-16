#include <iostream>
#include <string>
using namespace std;

int main() {

    int a = 20;
    int* ptr = new int;

    ptr = &a;

    a = 40;

    cout << "a: " << a << endl;
    cout << "ptr: " << ptr << endl; // print address of a
    cout << "*ptr: " << *ptr << endl; // print value of a

    return 0;
}
