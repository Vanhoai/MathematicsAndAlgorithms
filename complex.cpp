//
// Created by Aurora Study on 14/10/24.
//

#include "complex.h"

#include <cmath>
#include <iostream>

Complex create_complex(const double real, const double imagine) {
    const Complex complex = {real, imagine};
    return complex;
}

double get_real(const Complex complex) { return complex.real; }

/**
 * Get the imagine part of a complex number.
 *
 * @param complex the complex number.
 *
 * @return the imagine part of the complex number.
 */
double get_imagine(const Complex complex) { return complex.imagine; }

/**
 * Add two complex numbers.
 *
 * @param complex1 first complex number.
 * @param complex2 second complex number.
 *
 * @return the result of addition.
 */
Complex add_complex(const Complex complex1, const Complex complex2) {
    const Complex complex = {complex1.real + complex2.real,
                             complex1.imagine + complex2.imagine};
    return complex;
}

/**
 * Subtract two complex numbers.
 *
 * @param complex1 first complex number.
 * @param complex2 second complex number.
 *
 * @return a complex number which is the result of subtraction.
 */
Complex sub_complex(const Complex complex1, const Complex complex2) {
    const Complex complex = {complex1.real - complex2.real,
                             complex1.imagine - complex2.imagine};
    return complex;
}

/**
 * Multiply two complex numbers.
 *
 * @param complex1 first complex number.
 * @param complex2 second complex number.
 *
 * @return the result of multiplication.
 */
Complex mul_complex(const Complex complex1, const Complex complex2) {
    const double real =
        complex1.real * complex2.real - complex1.imagine * complex2.imagine;
    const double imagine =
        complex1.real * complex2.imagine + complex1.imagine * complex2.real;

    const Complex complex = {real, imagine};
    return complex;
}

/**
 * Divide two complex numbers.
 *
 * @param complex1 The first complex number.
 * @param complex2 The second complex number.
 * @return The result of division.
 */
Complex div_complex(const Complex complex1, const Complex complex2) {
    const double real =
        (complex1.real * complex2.real + complex1.imagine * complex2.imagine) /
        (complex2.real * complex2.real + complex2.imagine * complex2.imagine);
    const double imagine =
        (complex1.imagine * complex2.real - complex1.real * complex2.imagine) /
        (complex2.real * complex2.real + complex2.imagine * complex2.imagine);
    const Complex complex = {real, imagine};
    return complex;
}

/**
 * @brief Calculate the absolute value of a complex number.
 *
 * @param complex complex number.
 *
 * @return absolute value of the complex number.
 */
double abs_complex(const Complex complex) {
    return sqrt(complex.real * complex.real +
                complex.imagine * complex.imagine);
}
