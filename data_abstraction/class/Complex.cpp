#include "Complex.h";
#include <cmath>
#include <iostream>

Complex::Complex(double real, double image) {
    this->real = real;
    this->image = image;
}

double Complex::getReal() const { return real; }

double Complex::getImage() const { return image; }

double Complex::abs() const { return sqrt(real * real + image * image); }

Complex &operator+(const Complex &c1, const Complex &c2) {
    Complex c(c1.real + c2.real, c1.image + c2.image);
    return c;
}

Complex &operator-(const Complex &c1, const Complex &c2) {
    Complex c(c1.real - c2.real, c1.image - c2.image);
    return c;
}

Complex &operator*(const Complex &c1, const Complex &c2) {
    Complex c(c1.real * c2.real - c1.image * c2.image,
              c1.real * c2.image + c1.image * c2.real);
    return c;
}

Complex &operator/(const Complex &c1, const Complex &c2) {
    Complex c(c1.real / c2.real, c1.image / c2.image);
    return c;
}

ostream &operator<<(ostream &os, const Complex &c) {
    os << c.real << " + " << c.image << "i";
    return os;
}

void operator~(const Complex &c) { delete &c; }