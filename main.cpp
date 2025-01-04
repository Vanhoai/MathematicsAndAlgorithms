#include "linear_algebra/matrix.cpp"
#include <iostream>
using namespace std;

int main() {
    Matrix A({{-7, -5}, {4, 3}});
    Matrix B({{-2, -9}, {5, 23}});
    Matrix C({{2, -5}, {-1, 3}});

    try {
        Matrix Ans = A.inverse() * C * B.inverse();
        Ans.print();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
