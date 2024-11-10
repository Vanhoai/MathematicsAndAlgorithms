//
// Created by Aurora Study on 14/10/24.
//

#ifndef COMPLEX_H
#define COMPLEX_H

struct Complex {
    double real;
    double imagine;
};

Complex create_complex(double real, double imagine);
double get_real(Complex complex);
double get_imagine(Complex complex);
Complex add_complex(Complex complex1, Complex complex2);
Complex sub_complex(Complex complex1, Complex complex2);
Complex mul_complex(Complex complex1, Complex complex2);
Complex div_complex(Complex complex1, Complex complex2);
double abs_complex(Complex complex);

#endif   // COMPLEX_H
