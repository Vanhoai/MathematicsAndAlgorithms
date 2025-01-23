#ifndef COMPLEX_H

#define COMPLEX_H
struct Complex {
    double real;
    double image;
};

Complex createComplex(double real, double image);
double real(Complex complex);
double image(Complex complex);
double abs(Complex complex);
void print(Complex complex);

#endif   // COMPLEX_H