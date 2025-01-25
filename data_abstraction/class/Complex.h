#include <iostream>
using namespace std;

#ifndef COMPLEX_H

#define COMPLEX_H
class Complex {
private:
    double real;
    double image;

public:
    Complex(double real, double image) {
        this->real = real;
        this->image = image;
    }

    double getReal() const;
    double getImage() const;
    double abs() const;

    friend Complex &operator+(const Complex &c1, const Complex &c2);
    friend Complex &operator-(const Complex &c1, const Complex &c2);
    friend Complex &operator*(const Complex &c1, const Complex &c2);
    friend Complex &operator/(const Complex &c1, const Complex &c2);
    friend ostream &operator<<(ostream &os, const Complex &c);
    friend void operator~(const Complex &c);
};

#endif