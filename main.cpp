#include "linear_algebra/matrix.cpp"
#include <iostream>
using namespace std;

int main() {
    Matrix A({{-1, 4, -3}, {-1, 3, -2}, {1, -1, 1}});
    Matrix B({{-5, -2, 4}, {1, -3, 6}, {-1, 0, -2}});
    Matrix C({{-2, 5, -1}, {4, 0, -3}, {-2, 9, 8}});

    try {
        Matrix Ans1 = (C.transpose() * B) + (5.0 * A);
        Matrix Ans2 = (B.transpose() * A) - (4.0 * B);
        Ans2.print();
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
