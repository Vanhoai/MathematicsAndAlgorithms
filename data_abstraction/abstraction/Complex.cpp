#include "Complex.h"
#include <iostream>
#include <math.h>
using namespace std;

Complex createComplex(double real, double image) {
    Complex complex;
    complex.real = real;
    complex.image = image;
    return complex;
}

double real(Complex complex) { return complex.real; }

double image(Complex complex) { return complex.image; }

double abs(Complex complex) {
    return sqrt(real(complex) * real(complex) +
                image(complex) * image(complex));
}

void print(Complex complex) {
    cout << "Complex: " << complex.real << " " << complex.image << endl;
}

int main() { return 0; }